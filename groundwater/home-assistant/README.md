# Home Assistant

* `dashboard-card.yaml` - Lovelace card for Well 1 and Well 2 (gauges, node health, 7-day graph).

There is no template-sensor file any more: the **gateway** calculates *Water Table Depth Below Ground*
itself and exposes an editable **Sensor Depth Below Ground** number per well. If you re-lower a probe,
change that number in Home Assistant (Settings > Devices > Groundwater Gateway); no reflashing is needed.

Useful entities per well: `Node Online` (false after 2.5 h without a packet), `Water Below Sensor`
(water level at or below the probe), `Battery Voltage`. Use them for notifications, for example
"Node Online turns off for 10 minutes" or "Battery Voltage below 3.5 V".
