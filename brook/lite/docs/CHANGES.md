# Changes

## Boost converter switch (26 November 2026)
* **Through-hole switch:** the switch is now a **BC327 PNP + BC337 NPN** transistor pair (10 kΩ, 470 Ω, 4.7 kΩ, 100 kΩ), all normal-legged parts from Otronic. The SMD AO3401A needed hard-to-get adapters and the through-hole NDP6020P is discontinued. The old AO3401A + 2N7000 version still works; firmware unchanged.
* The MT3608 now runs from the **battery** through its own MOSFET switch (AO3401A + 2N7002/2N7000) on `GPIO7`, as in `groundwater/`. The 18 V loop no longer loads the Heltec's 3.3 V regulator / `Vext`.
* New measuring order: BME280, DS18B20 and EC with the loop **off** (no loop current in the water while the EC probe is excited), then boost on, `warmup` 1 s, level, boost off. The battery is read before the boost converter is on.
* `warmup` is now the settling time after the boost switch (1000 ms, was 700 ms after boot). `ds18b20_wait` (900 ms) is replaced by `ds18b20_wait_rest` (default 0 ms; the DS18B20 converts during the warm-up).
* The boost converter is on about 1 s per cycle instead of about 2-3 s: estimated 10-17 mAh per day at 10 minutes (was 17-25).
* The switch output is shared: `shared/esphome/heltec-v3/boost-switch.yaml`; circuit, parts and how to solder the SOT-23 MOSFET on an adapter: `shared/docs/boost-switch.md`.
* **Rewiring needed** if you already built a node: move the MT3608 input from `Vext` to the MOSFET output and wire `GPIO7`. BOM: +€1.
* Checked with `esphome config` before and after: `groundwater/` renders identically (only the new `boost_pin` substitution); `brook/lite/` differs only in the new output and the script order.

## Shared parts moved to `shared/` (24 November 2026)
* Board, LoRa radio, outputs, buses, battery sensor, deep sleep, the level and EC inputs, the gateway base and the openSenseMap upload now come from `shared/esphome/` (same as `groundwater/`).
* Level and EC formulas: `shared/esphome/include/water_calc.h` (same results).
* `docs/REFERENCES.md` is now `shared/docs/REFERENCES.md`; cable splicing, EC calibration and the board-revision check are in `shared/docs/`.
* Checked by rendering both configs with `esphome config` before and after: only the formulas, the upload call and the header include differ.

## 24 November 2026: moved into `water-management-brook-groundwater`
* Now lives in `brook/lite/` of the combined repository, next to `brook/full/` and `groundwater/`. CI runs from the repository root.

## First version (23 November 2026)
A simple brook station as a first step towards the full station (now `brook/full/`). It is the groundwater lite design (the former `lite` branch of the groundwater repository), adapted to a brook:

* **Level:** TL-136 with a **0-2 m** range (`range_m`), 100 Ω shunt, ESP32 ADC. The gateway reports *Water Level* on the staff gauge = water above sensor + editable *Sensor Height Above Gauge Zero*. New flags: *Sensor Dry* and *Level Above Sensor Range*.
* **Interval:** 10 minutes (was 60 for groundwater); low-battery sleep 2 h; *Node Online* timeout 35 min.
* **Radio:** 869.525 MHz (10 % duty-cycle sub-band), as on the full station.
* **BME280:** air temperature, humidity **and pressure** (pressure is measured anyway, and helps to spot a blocked vent tube).
* **EC:** DFRobot SEN0244 with two-point calibration; not uploaded while the sensor is dry.
* **openSenseMap:** six values per station.
* **Docs:** field guide rewritten for a brook (stilling pipe, staff gauge, permission, flood checks, monthly cleaning, power budget at 10 minutes), BOM (2 × 18650 in parallel, stilling pipe, conduit, post, staff gauge), new installation diagram.
* Includes the two compile fixes found in the groundwater repo (`random_uint32()`, `token.c_str()`).
* Validated with ESPHome 2026.11.0: `esphome config` and `esphome compile` pass in CI for the node and the gateway. Not tested on hardware.
