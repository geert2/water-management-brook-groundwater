# Home Assistant

* `dashboard-card.yaml` - Lovelace card for Well 1 and Well 2 (gauges, node health, 7-day graph).

There is no template-sensor file any more: the **gateway** calculates *Water Table Depth Below Ground*
itself and exposes an editable **Sensor Depth Below Ground** number per well. If you re-lower a probe,
change that number in Home Assistant (Settings > Devices > Groundwater Gateway); no reflashing is needed.

Useful entities per well: `Node Online` (false after 2.5 h without a packet), `Water Below Sensor`
(water level at or below the probe), `Battery Voltage`. Use them for notifications, for example
"Node Online turns off for 10 minutes" or "Battery Voltage below 3.5 V".

Data quality entities per well (`QC Flags`, `Readings Lost`, `Node Resets`, idea taken from the Meetbeek set):

| QC bit | Meaning |
|--------|---------|
| 1 | level loop outside 3.5-22 mA (broken wire, short, boost fault) |
| 2 | EC missing or outside 0-`ec_max_us` |
| 4 | groundwater temperature missing or outside -2 to 35 °C |
| 8 | battery below `low_battery_v`, or not read |
| 16 | EC not calibrated (`wN_ec_calibrated` is "0") |
| 32 | depth not calibrated (`wN_depth_calibrated` is "0") |

`Readings Lost` counts gaps in the node's packet counter; `Node Resets` counts how often the counter restarted
(a power loss at the node). Both reset to 0 when the gateway reboots. The `Depth Shunt Voltage` and `EC Raw Voltage`
diagnostic entities keep the raw values, so any history can be recalculated after a new calibration.
