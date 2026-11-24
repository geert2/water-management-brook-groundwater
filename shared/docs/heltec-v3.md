# Heltec WiFi LoRa 32 V3: board notes

*Shared by `groundwater/` and `brook/lite/`. The ESPHome side is in [`../esphome/heltec-v3/`](../esphome/heltec-v3/). `[R#]` tags: [REFERENCES.md](REFERENCES.md).*

## Pins used by every node

| Function | Heltec V3 pin | Notes |
| :--- | :--- | :--- |
| Vext enable | `GPIO36` | switched 3.3 V sensor rail; **LOW = ON** on V3/V3.1 (`vext_active_low`) |
| DS18B20 data | `GPIO4` | 4.7 kΩ pull-up to `Vext` |
| I²C SDA / SCL | `GPIO41` / `GPIO42` | separate from the onboard OLED bus; 50 kHz; BME280 and/or ADS1115, powered from `Vext` |
| TL-136 shunt voltage | `GPIO5` (ADC1) | via 1 kΩ, 3.6 V zener and 100 nF (see the project's `docs/wiring.md`) |
| EC module output | `GPIO6` (ADC1) | DFRobot SEN0244, 0-2.3 V |
| Battery ADC | `GPIO1` | divider 390 k / 100 k (factor 4.9) [R12] |
| Battery divider enable | `GPIO37` | polarity depends on the board revision, see below |
| Status LED | `GPIO35` | flashes once at every wake-up |
| LoRa SX1262 | `GPIO8/9/10/11/12/13/14` | onboard; `tcxo_voltage: 1_8V`, `rf_switch: true` [R10] |

A project can add its own pins (for example `GPIO7` for the boost switch in `groundwater/`).

## Board revision check (do this once per board)
The polarity of two pins differs between Heltec V3 revisions, and the firmware has two settings for it (defaults in `shared/esphome/heltec-v3/node-base.yaml`, override them in the node file):

| Setting in the node file | V3.0 / V3.1 | V3.2 | Source |
| :-- | :-- | :-- | :-- |
| `vbat_ctrl_active_low` (GPIO37) | `"true"` | `"false"` (default) | [R11] [R13] |
| `vext_active_low` (GPIO36) | `"true"` (default) | **not confirmed**, check | [R10] [R11] [R14] |

1. Read the revision printed on the board (V3.2 is the current one).
2. **Battery:** with the battery connected and the node awake, *Battery Voltage* should match a multimeter within a few percent after adjusting `vbat_scale`. A reading near 0 V means the polarity is wrong (the firmware then ignores the reading and carries on measuring).
3. **Vext:** measure between the `Ve` pin and `GND` while the node is awake (it switches `Vext` on in early boot). About 3.3 V means the setting is right. If it reads 0 V, flip `vext_active_low`. Compare with the V3.2 schematic [R14] if in doubt.
4. A cleaner test: flash a minimal config that only toggles `GPIO36` and `GPIO37`, and watch the voltages.

Check the battery reading against a multimeter once. If it is off, adjust `vbat_scale` in the node file (default 4.9 for the 390 k / 100 k divider [R12]; ESPHome's device page uses 2.0 [R10]).

## Practical rules
* **Never power the board without the 868 MHz antenna** screwed on: transmitting into an open connector can damage the SX1262 amplifier.
* **Re-flashing a node:** nodes sleep right after each reading and have no Wi-Fi, so updates need USB. Hold **BOOT** while pressing **RST** to enter the bootloader.
* **Deep-sleep current:** expect tens to a few hundred µA for the whole board; Heltec quotes under 10 µA for a related board [R15], treat that as a best case. Measure it with a µA-capable meter in series with the battery: above about 100 µA, battery life is limited by the sleep current rather than by the measurements.
* **Charging:** the board charges one Li-ion cell from USB and has no deep-discharge cut-off, so use **protected** 18650 cells, and **never charge below 0 °C**.
* **Vext load:** the 3.3 V regulator also feeds the ESP32 and the radio. Keep large loads (an 18 V boost converter for the TL-136 loop) on their own switch where possible, as `groundwater/` does on `GPIO7`.
