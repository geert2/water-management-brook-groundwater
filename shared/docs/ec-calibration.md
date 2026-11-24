# EC sensor (DFRobot SEN0244): two-point calibration

*Shared by `groundwater/` and `brook/lite/`. The conversion itself is `sen0244_ec25()` in [`../esphome/include/water_calc.h`](../esphome/include/water_calc.h). `[R#]` tags: [REFERENCES.md](REFERENCES.md).*

Cheap analog EC/TDS probes vary from batch to batch, and the longer cable changes the response. Calibrate each probe **after** extending its cable.

## Where the numbers go

| Project | Gain / offset | Re-flash | Notes |
| :-- | :-- | :-- | :-- |
| `groundwater/` | `wN_ec_gain`, `wN_ec_offset` in `esphome/gateway/water-well-gateway.yaml` | the **gateway** (over Wi-Fi) | set `wN_ec_calibrated: "1"` afterwards; the raw voltage stays visible as *EC Raw Voltage* |
| `brook/lite/` | `ec_gain`, `ec_offset` in `esphome/nodes/brook-lite-node-1.yaml` | the **node** (USB) | |

Start with gain `"1.0"` and offset `"0.0"`, so you read the uncalibrated value.

## Procedure
1. **Rinse & dry:** rinse the probe tips with distilled water and blot dry.
2. **Low standard:** place the **EC probe and the DS18B20** in **84 µS/cm** solution; swirl to remove air bubbles; wait 60 s. Trigger a reading (press **RST** once) and note the reported *Electrical Conductivity* as `M1`.
3. **High standard:** rinse and repeat with **1413 µS/cm**, giving `M2`.
4. **Calculate:**
   `gain = (1413 - 84) / (M2 - M1)`
   `offset = 84 - gain × M1`
5. Enter both numbers (see the table above), re-flash, and verify that both standards now read correctly.

*Single-point fallback (only 1413 µS/cm available):* `gain = 1413 / M`, `offset = 0`. This is less accurate, especially at low conductivity.

## Limits
The DFRobot analog sensor is specified for 0-1000 ppm TDS (about 0-2000 µS/cm at the usual 0.5 factor) with an accuracy of ±10 % of full scale at 25 °C [R19]. Treat readings above that range as "high", not as precise numbers, and expect a few hundred µS/cm of uncertainty even after calibration. Recalibrate about once a year, and check against a handheld EC meter in between.
