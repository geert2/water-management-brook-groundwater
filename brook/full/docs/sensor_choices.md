# Sensor choices for the full brook station

This station monitors **De Grote Beek** (Hansbeke, East Flanders), a small stream in an agricultural, sandy-loam area. The sensors were chosen for **scientific value**, **cost**, **practicality** and **educational value**, and must survive outdoors.

> Simpler alternative: [`../../lite/`](../../lite/) measures level, water temperature, EC and air temperature/humidity/pressure only. It deliberately leaves out turbidity (hard to keep watertight and clean, and its data is hard to interpret) and dust (a dedicated sensor.community kit does that better).

What to expect from all of them: **trustworthy trends and events**, not laboratory accuracy (see the table in the [README](../README.md)).

---

## Water sensors

### Core

| Sensor | Measures | Approx. cost | Why |
|--------|----------|-------------:|-----|
| **TL-136** (4-20 mA, vented cable) | water level, hydrostatic pressure, 0-1 m range in this design | €19 | The level is the backbone: floods, droughts and the context for every other value. A vented 4-20 mA loop is robust against long cables and electrical noise. |
| **DS18B20** (waterproof) | water temperature, ±0.5 °C | €3.50 | Temperature drives oxygen solubility and reaction rates, and it is needed to compensate the EC reading. |
| **DFRobot SEN0244** (Gravity analog TDS) | electrical conductivity, about 0-2000 µS/cm, ±10 % of full scale | €12-14 | EC is a proxy for dissolved salts and nutrients: fertilizer run-off, discharges, and dilution by rain. |

**Accuracy in practice:**
* **TL-136:** good to roughly a centimetre after checking against a staff gauge, not millimetres. The ADS1115 and calibration help; the sensor's own specification and the 4-20 mA conversion limit the rest.
* **EC:** needs a calibration in 1413 µS/cm standard and a re-check about every 3 months ([calibration.md](calibration.md)).

**Reference data:** compare your EC and temperature with VMM's public water-quality measurements at nearby stations rather than with fixed "typical" values; they differ per stream and season.

### Added value (the extras of the full station)

| Sensor | Measures | Approx. cost | Why |
|--------|----------|-------------:|-----|
| **DFRobot SEN0189** (Gravity analog turbidity) | relative turbidity index (output voltage falls as water gets cloudier) | €19 | EC sees **dissolved** matter; turbidity sees **suspended** matter (silt, clay, algae). A turbidity spike after rain points to soil erosion from fields. |
| **JSN-SR04T** (waterproof ultrasonic) | distance from above to the water surface | €9 | An independent level reading with different physics: it cross-checks the TL-136, shows when the TL-136 drifts or fails, and keeps measuring above the TL-136 range during floods. |

**Limits of the turbidity sensor (be honest about them):**
* It is a low-cost optical sensor designed for appliances. **The top of the probe is not waterproof** (DFRobot), so it needs a sealed housing.
* It gives a **relative index**, coarse below about 50 NTU, and drifts as the window fouls. It is useful as a storm detector, not as NTU values comparable with official measurements.
* It needs **weekly cleaning**; log every cleaning so jumps in the data can be explained.

---

## Air sensors (separate air-quality node)

| Sensor | Measures | Approx. cost | Why |
|--------|----------|-------------:|-----|
| **SDS011** | PM2.5 / PM10 | €25 | The standard sensor of [sensor.community](https://sensor.community): the data appears on its world map and can be compared with neighbours. |
| **BME280** | air temperature, humidity, pressure (±1 °C, ±3 % RH, ±1 hPa) | €6 | Context for both water and air data, and the humidity needed to judge SDS011 readings. |

**Limits:** the SDS011 is **indicative**. It reads too high when the relative humidity is above about 70 %, which is common next to a brook. It is a useful trend sensor, not a reference instrument.

**Why a separate node:** the SDS011 needs 5 V and its fan draws far more power than the battery-powered water node can afford. The air node runs from a **5 V USB supply** (ESP32 DevKit), can be placed where the air flows freely, and keeps working if the water node fails (and the other way round).

---

## Power (water node)

| Component | Role |
|-----------|------|
| **12 V solar panel, about 10 W** | energy source |
| **CN3791** MPPT charger | charges the Li-ion cells safely (CC/CV, 4.2 V) from the 12 V panel |
| **2 × 18650 in parallel (1S2P)**, protected, 2 A fuse | storage at 3.7 V with double capacity |
| **2 × MT3608** boost modules (5 V and about 15 V), powered from the Heltec `Vext` switch | sensor supplies, off during deep sleep |

**Why these choices:**
* **CN3791, not an XL6019:** an XL6019 is a DC-DC converter, not a charger. It has no CC/CV profile and can overcharge Li-ion cells.
* **Parallel, not series:** the CN3791 and the Heltec charge a single cell (1S). Two cells in series (7.4 V) would need a 2S charger and balancing.
* **MT3608, not XL6009:** the XL6009 needs at least 5 V input, more than a Li-ion cell gives.
* Li-ion must **not be charged below 0 °C**.

---

## Communication

**LoRa at 869.525 MHz** (869.4-869.65 MHz sub-band, 10 % duty cycle) between two Heltec V3 boards, raw LoRa without a network server.

* Sub-GHz radio reaches a few hundred metres through trees and houses much more reliably than 2.4 GHz Wi-Fi, at a fraction of the power.
* Point-to-point is simpler than a Wi-Fi mesh and has no relay hops that can fail.
* The Heltec V3 has the SX1262 radio built in. LoRaWAN stays possible later with the same chip.
* Range depends strongly on the site: test the link before installing (see [bench-test.md](bench-test.md)).

---

## Approximate cost

Indicative 2026 prices; check current prices before ordering.

| Group | Items | Approx. |
|-------|-------|--------:|
| Water sensors | TL-136, DS18B20, SEN0244, SEN0189, JSN-SR04T | €63 |
| Air sensors | SDS011, BME280 | €31 |
| Electronics | 2 × Heltec V3, ESP32 DevKit, ADS1115, 2 × MT3608, CN3791, small parts | €95 |
| Power | 10 W panel, 2 × 18650 | €25 |
| Housing | IP66 boxes, glands, PVC pipe | €22 |
| **Total** | | **≈ €235** |

This is above the original €150-200 target. Without turbidity and the air node it drops by about €60; the [lite station](../../lite/) is cheaper still.

---

## Deliberately not measured

| Parameter | Why not (for now) |
|-----------|-------------------|
| **pH** | probe costs €50+, glass electrode is fragile, needs frequent calibration |
| **Dissolved oxygen** | €100+ for a usable probe, frequent calibration and maintenance. It cannot be derived from EC and temperature; temperature only gives the maximum (saturation) value. |
| **Nitrate, ammonium** | ion-selective probes cost €200+ and drift quickly. EC shows changes in dissolved matter but cannot tell which substance. |
| **ORP** | hard to interpret without other chemistry |

These are better covered by occasional **test-strip or photometer measurements** by volunteers, logged next to the station data, or by VMM's own sampling.

**Possible later additions:** pH, a second station further along the stream, or periodic transparency-tube readings as a simple, interpretable turbidity reference.

---

## Educational value

* **Level and temperature:** hydrostatic pressure, flood response, seasonal cycles.
* **EC:** what dissolved salts and nutrients do, and why rain dilutes the brook.
* **Turbidity and ultrasonic:** different ways to measure the same thing, and why cross-checking matters.
* **Air node:** air quality, humidity effects on sensors, and contributing to a worldwide network.
* **Data literacy:** calibration, quality flags, and comparing citizen data with official VMM data.
