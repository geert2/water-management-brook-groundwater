# Water management: brook & groundwater citizen science

Open-source, low-cost monitoring stations built by volunteers: **Heltec WiFi LoRa 32 V3** (ESP32-S3 + SX1262) nodes in the field, raw LoRa to a gateway at home, data in **Home Assistant** and on public maps. All firmware is ESPHome YAML.

| Project | Folder | What it measures | Status |
| :-- | :-- | :-- | :-- |
| **Groundwater** | [`groundwater/`](groundwater/) | water table depth (TL-136 0-5 m), groundwater temperature, EC, optional BME280; hourly; openSenseMap | validates and compiles, not yet field-tested |
| **Brook lite** | [`brook/lite/`](brook/lite/) | water level on the staff gauge (TL-136 0-2 m), water temperature, EC, air temperature, humidity and pressure; every 10 min; openSenseMap | validates and compiles, not yet field-tested |
| **Brook full** ("De Meetbeek") | [`brook/full/`](brook/full/) | level (TL-136 + ultrasonic), water temperature, EC, turbidity, solar power, separate PM2.5/PM10 air node; MQTT | validates; open PRs pending |

Start with the README in the project folder: each one has its own BOM, wiring notes, field guide, ESPHome configs and Home Assistant dashboard.

## Which one do I build?
* **A well or piezometer** under farmland → `groundwater/`.
* **A brook, first station** → `brook/lite/`: the same simple hardware as the groundwater node, with a 0-2 m level sensor and a 10-minute cycle.
* **A brook, full research station** → `brook/full/` (more sensors, solar, more work to build and maintain).
* **Air quality / dust** → a dedicated [sensor.community](https://sensor.community) kit is the better choice; it has its own map and archive.

## Repository layout

```text
.github/
  workflows/esphome.yml     # CI: esphome config + compile for all three projects
  scripts/dummy-secrets.sh  # fills secrets.yaml.example with test keys for CI
groundwater/                # from geert2/Groundwater-citizen-science-sensors-with-Lora-and-Home-Assistant-
brook/
  lite/                     # brook lite station
  full/                     # from geert2/citizen-science-Brook-monitoring-
LICENSE                     # MIT
```

The git history of both original repositories is kept: `git log -- groundwater/` and `git log -- brook/full/` show it.

## Secrets
Every project has an `esphome/secrets.yaml.example`. Copy it to `secrets.yaml` in the same folder (it is git-ignored) and fill it in. Never commit a real `secrets.yaml`.

## Contributing
* One pull request per project where possible; CI checks every config on every push.
* Field reports (what worked, what broke, real battery life) are very welcome as issues.

## Licence
MIT, see [`LICENSE`](LICENSE).
