# Changes after the technical review

Validated with ESPHome 2026.10.2 (`esphome config`, zero warnings) for both nodes and the gateway. The C++ was **not** compiled here and nothing has been tested on hardware.

## Build blockers fixed
* `sx126x`: added `hw_version` and `modulation`, renamed `output_power` to `pa_power`, `coding_rate` to `CR_4_5`, added `tcxo_voltage: 1_8V` (Heltec V3 TCXO on DIO3) and `crc_enable`.
* Removed the unsupported ADC option `sample_duration`; use `samples` + `sampling_mode`.
* Gateway `packet_transport`: the key moved from the top level to each provider.
* Gateway sensors: added `internal: false`; `headers:` renamed `request_headers:`.
* Fixed the unescaped quotes in the openSenseMap JSON (now a raw string literal).
* `secrets.yaml` must sit next to each config: added `esphome/sync-secrets.sh` and documented it.

## Functional bugs fixed
* Gateway sensors now map to the node's broadcast IDs via `remote_id` (they never matched before).
* The node now sends explicitly (`update_interval: never` + `component.update: lora_transport`); before, it went to sleep before the first broadcast.
* DS18B20 is given time to convert; EC temperature compensation now uses the real temperature.
* Battery divider enabled with GPIO37 LOW (it was driven HIGH); battery is read before the boost loads the cell.
* The gateway depth is recomputed when the column value arrives, so the upload no longer uses the previous hour's value.
* openSenseMap `Authorization` header now sends the raw box token (no `Bearer`); NaN values are skipped instead of corrupting the JSON; HTTP errors are logged.
* LoRa radio is put to sleep before deep sleep; transmit wait is 1.5 s; broadcast IDs are shortened.

## Electrical / measurement changes
* Shunt **100 Ω** by default (160 Ω gives 3.2 V at 20 mA, above the ADC range; it still works below about 4.8 m, see `docs/wiring.md`); `shunt_ohm` is configurable. The valid current window is 3.5-22 mA.
* Added protection network (1 kΩ + 3.6 V zener + 100 nF) and a boost-input capacitor to the BOM and `docs/wiring.md`.
* Per-node `zero_offset_m`, `span_scale`, `ec_gain`, `ec_offset` substitutions instead of editing the shared file.
* True two-point EC calibration procedure; EC wiring corrected to two cores for the probe.
* Breather vent for the enclosure; hanging line instead of hanging from the cables.

## Power
* Lower CPU clock (80 MHz), WARN-level logging, ESP-IDF framework, random 0-30 s wake-up jitter.
* Low-battery mode (< 3.4 V): report voltage only, sleep 6 h.
* Sensor power (`Vext`, including the boost converter) is now on for roughly 2 s per cycle instead of 3.5 s, about 40 % less active energy. Further gains need a separate boost switch and a measured `warmup`.
* README claim reworded to "roughly 1-2 years, measure it".

## Gateway / Home Assistant
* One reusable `well-package.yaml` per well (add a well in about 15 lines).
* Editable *Sensor Depth Below Ground* number per well, *Water Below Sensor* and *Node Online* entities.
* The duplicate Home Assistant template sensor was removed; the dashboard covers both wells, uses `secondary_info: last-updated` and corrected gauge bands.
* Gateway: fallback hotspot, captive portal, Wi-Fi signal sensor. OTA is encrypted with the API key.
* GitHub Actions workflow validating all configs.

## BME280 (added on request)
* Optional BME280 on a separate I²C bus (`GPIO41/42`), powered from `Vext`; sends enclosure temperature, air pressure and humidity (+3 values per packet).
* Gateway exposes them per well; dashboard shows them (humidity as a desiccant check).

## ADS1115 option (added on request)
* `esphome/nodes/depth-adc-esp.yaml` (default) and `depth-adc-ads1115.yaml` (differential A0-A1, 16 sps) provide the `depth_voltage` sensor; the node file chooses one. `water-well-node-example-ads1115.yaml` is a ready example.

## Start-up fix (found while adding the BME280/ADS1115)
* The DS18B20, BME280 and ADS1115 are detected **once during start-up**, but `Vext` was only switched on later by the measurement script, so they would not have been found (the temperature probe included, which was also true of the original design). `Vext` is now switched on at boot priority 750 (after the GPIO output exists, before sensors are set up), with a 30 ms power-up delay.
* Side effect: the battery is now read with the boost converter already running, so the reading sags slightly (roughly tens of mV). Calibrate `vbat_scale` against a multimeter.

## Diagrams
* `docs/img/` holds four SVG diagrams (node wiring overview, depth front end with ESP ADC and with ADS1115, well installation) embedded in the README, `docs/wiring.md` and the field guide.

## Source check (17 November 2026)
* All sources are listed in [`REFERENCES.md`](REFERENCES.md), with what was read, what was only seen in search results and what is still unverified.
* **Correction:** the battery-divider enable on GPIO37 is active LOW on Heltec V3/V3.1 but **active HIGH on V3.2**. It is now the `vbat_ctrl_active_low` setting (default V3.2). Vext polarity on V3.2 could not be confirmed and is the `vext_active_low` setting.
* The low-battery mode now ignores readings below 2 V, so a wrong divider setting cannot lock a node into 6-hour sleep.
* **Correction:** TL-136 supply is listed as 12 to 32 V, not 9 to 12 V. EC sensor accuracy is ±10 % of full scale. The input capacitor on the boost converter is a precaution (the MT3608 has soft start).
* `[R#]` tags added in the YAML comments, README, BOM, wiring notes and field guide.

## Not implemented (ideas)
* Separate MOSFET for the boost converter so EC/temperature are read without the 18 V loop on.
* Double transmission / acknowledgements, rolling codes, node maintenance mode with Wi-Fi OTA.
* `createdAt` timestamps on openSenseMap uploads and retry queue.
* Confirm the dashboard entity IDs and the openSenseMap authentication against your own box (the openSenseMap API has been changing).
