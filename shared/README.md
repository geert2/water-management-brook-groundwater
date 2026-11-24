# shared/: parts used by more than one station

`groundwater/` and `brook/lite/` are built from the same hardware (Heltec WiFi LoRa 32 V3, TL-136 4-20 mA loop, DS18B20, DFRobot SEN0244 EC probe, BME280) and the same firmware pattern (ESPHome, raw LoRa with `packet_transport`, deep sleep, a gateway that feeds Home Assistant and openSenseMap). Everything they have in common lives here, so a fix reaches both.

> **A change here affects every station that uses it.** CI validates and compiles all of them on every push, so check that it is green before merging.

## Firmware: `esphome/`

| File | What it contains | Used by |
| :-- | :-- | :-- |
| `heltec-v3/board.yaml` | ESP32-S3, 8 MB flash, ESP-IDF | everything below |
| `heltec-v3/lora.yaml` | SPI + SX1262 radio; set `lora_frequency` | nodes and gateways |
| `heltec-v3/node-base.yaml` | 80 MHz CPU, logger, Vext / battery-divider / LED outputs, 1-Wire on `GPIO4`, I²C on `GPIO41/42` (50 kHz), battery sensor, deep sleep, `water_calc.h` | groundwater and brook lite nodes |
| `sensors/tl136-adc-esp.yaml` | TL-136 shunt voltage on `GPIO5`, ESP32 ADC (`depth_voltage`) | groundwater (default), brook lite |
| `sensors/tl136-adc-ads1115.yaml` | the same via an ADS1115, differential A0-A1 | groundwater (option) |
| `sensors/ec-sen0244-adc.yaml` | EC module output on `GPIO6` (`ec_voltage`) | groundwater, brook lite |
| `gateway/gateway-base.yaml` | Wi-Fi, Home Assistant API, OTA, LoRa radio, Wi-Fi signal sensor, `water_calc.h`; set `gateway_ap_ssid`, `lora_frequency` | both gateways |
| `gateway/opensensemap.yaml` | `upload_to_opensensemap` script (lists of sensor IDs, values and decimals; NaN values are skipped); set `gateway_useragent` | both gateways |
| `include/water_calc.h` | `tl136_loop_ma()`, `tl136_column_m()`, `sen0244_ec25()` | lambdas in nodes and gateways |

**How a project uses them:** as ESPHome packages, with a path relative to the project file, for example in `groundwater/esphome/nodes/common-well-node.yaml`:

```yaml
packages:
  node_base: !include ../../../shared/esphome/heltec-v3/node-base.yaml
  ec_adc: !include ../../../shared/esphome/sensors/ec-sen0244-adc.yaml
```

`brook/lite/` is one folder deeper, so it uses `../../../../shared/...`.

**Overriding defaults:** a shared file sets defaults in its own `substitutions:` (for example `vbat_ctrl_active_low`, `lora_frequency`). A value in the project's `substitutions:` always wins.

**Not shared (on purpose):** packet layout (`packet_transport` sensors), the measurement script (boost switch, warm-up, low-battery behaviour), calibration and per-station logic. These differ between a well and a brook.

**`brook/full/` does not use `shared/` yet.** It has its own radio protocol (`B1,...` lines), an ADS1115 for all inputs and a different EC calibration (temperature coefficient and k-factor), so switching it over would change its results. See its review notes.

## Documentation: `docs/`

| File | Content |
| :-- | :-- |
| [`docs/heltec-v3.md`](docs/heltec-v3.md) | pins, board revision check (Vext and battery-divider polarity), antenna, re-flashing, deep-sleep current, charging |
| [`docs/cable-splicing.md`](docs/cable-splicing.md) | waterproof splices for the DS18B20 and EC probe cables (Marine Triple-Seal Method) |
| [`docs/ec-calibration.md`](docs/ec-calibration.md) | two-point EC calibration, and where the numbers go in each project |
| [`docs/REFERENCES.md`](docs/REFERENCES.md) | sources behind the `[R#]` tags in both projects |
