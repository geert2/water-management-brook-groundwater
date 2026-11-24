# Bill of Materials (BOM) & Sourcing Guide

This checklist covers all hardware, waterproofing consumables, and gateway parts needed to build and deploy a groundwater monitoring station. Prices are approximate (including VAT) based on Benelux/EU electronics suppliers.

---

## 1. Per-Well Field Node (~€90 - €110)
Build one of these units for each observation well (piezometer) you want to monitor.

| Status | Component | Exact Specification | Qty | Approx. Cost | Suggested Suppliers (BE / NL / EU) |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Microcontroller** | Heltec WiFi LoRa 32 V3 (**868 MHz** EU version, ESP32-S3 + SX1262). Note the revision on the silkscreen (V3.0, V3.1 or V3.2): it decides the battery-divider polarity, see `docs/wiring.md` | 1 | €21 - €25 | TinyTronics, Otronic |
| [ ] | **Depth Sensor** | TL-136 Submersible Level Transmitter (**0-5 m**, **4-20 mA**, 5 m+ **vented** cable) | 1 | €25 - €35 | Amazon.com.be, AliExpress |
| [ ] | **EC / Water Quality Sensor** | DFRobot Gravity Analog TDS/EC Sensor Module + Probe (probe has **two** electrode wires) | 1 | €12 - €14 | TinyTronics, BerryBase |
| [ ] | **Temperature Probe** | Waterproof DS18B20 Digital Probe (1 m cable) | 1 | €3 | Gotron, Otronic |
| [ ] | **Step-Up Boost Module** | MT3608 DC-DC Adjustable Step-Up Converter (set to **18.0 V**) | 1 | €2 | TinyTronics, Otronic |
| [ ] | **BME280 module** *(optional)* | BME280 breakout, 3.3 V, I²C (4 pins). Check it is a real BME280 (with humidity) and not a BMP280. | 1 | €4 - €6 | TinyTronics, Otronic, AliExpress |
| [ ] | **Shunt Resistor** | **100 Ω** (or 160 Ω, see `docs/wiring.md`) metal film, **0.1 %** (25 ppm), 0.25 W | 1 | €0.50 | Gotron, Mouser, Farnell |
| [ ] | **Input Protection** | 1 kΩ resistor, **3.6 V zener** (e.g. BZX84C3V6 or 1N5227B), 100 nF ceramic capacitor | 1 set | €0.50 | Gotron, Otronic |
| [ ] | **Boost Input Capacitor** | 220 - 470 µF low-ESR electrolytic, ≥ 10 V | 1 | €0.50 | Gotron, Otronic |
| [ ] | **Pull-Up Resistor** | 4.7 kΩ resistor (0.25 W, for DS18B20 data line) | 1 | €0.10 | Gotron *(often included with DS18B20)* |
| [ ] | **Battery & Holder** | **Protected** 18650 Li-Ion cell (3000 mAh+, e.g. Samsung 35E with protection) + 1x 18650 holder | 1 | €8 - €12 | TinyTronics, NKON |
| [ ] | **Waterproof Enclosure** | IP65 Outdoor Junction Box (approx. 150 x 110 x 70 mm) | 1 | €7 - €9 | Hubo, Brico |
| [ ] | **Enclosure Breather Vent** | M12 or PG7 membrane vent plug (IP67/IP68, e.g. Gore-type) for the TL-136 vent | 1 | €2 - €4 | Amazon.com.be, RS, Farnell |
| [ ] | **Cable Glands** | PG9 or PG11 Waterproof Nylon Cable Glands (with rubber seals) | 3 | €2 | Hubo, Brico |
| [ ] | **Desiccant** | Silica Gel Packets (10 g-20 g) | 2 | €1 | Amazon.com.be |
| [ ] | **Assembly parts** | Perfboard or small PCB, screw terminals, hook-up wire, standoffs, cable ties | 1 set | €4 - €6 | Gotron, Hubo |
| [ ] | **Hanging line** | 2-3 mm stainless wire or Kevlar line (≥ 5 m) + clamp, so the probe bundle does not hang from its cables | 1 | €3 - €5 | Hubo, Brico |
| [ ] | **Manual dip meter** *(shared)* | Beeper tape/dip meter or a weighted tape measure, for cross-checking depth | 1 per group | €15 - €40 | hydro suppliers, Amazon.com.be |

*Optional accuracy upgrade:* **ADS1115** 16-bit I²C ADC module (€3 - €5) for the depth channel; see `docs/wiring.md`. *Optional range:* external 868 MHz antenna with bulkhead SMA pigtail (€6 - €9).

---

## 2. Submersible Cable Waterproofing (~€10, Shared Across Multiple Nodes)
Needed to extend the short factory cables on the EC and DS18B20 probes down to 4.5 metres.

| Status | Item | Specification | Qty | Approx. Cost | Suggested Suppliers |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Extension Cable** | Flexible waterproof rubber cable (H05RN-F, 3 x 0.5 mm²). The DS18B20 uses all three cores; the EC probe uses **two** (twisted pair or screened is better). | 8 m | €6 - €8 | Hubo, Brico |
| [ ] | **Adhesive Heat-Shrink** | **3:1 Dual-Wall Marine Adhesive-Lined** Heat-Shrink Tubing (3 mm & 10 mm) | 1 pack | €5 | Amazon.com.be, Gotron |
| [ ] | **Rubber Sealing Tape** | Self-Amalgamating Silicone/Rubber Tape | 1 roll | €5 | Hubo, Brico |
| [ ] | **Cable Ties** | UV-Resistant Black Nylon Zip Ties | 1 pack | €2 | Hubo, Brico |

---

## 3. Central Farmhouse Gateway (~€21 - €30, One-Time Purchase)
One gateway receives LoRa packets from all neighbouring wells and uploads them to Home Assistant and openSenseMap.

| Status | Component | Exact Specification | Qty | Approx. Cost | Suggested Suppliers |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Gateway Board** | Heltec WiFi LoRa 32 V3 (**868 MHz** EU version) | 1 | €21 - €25 | TinyTronics, Otronic |
| [ ] | **Power Supply** | Plain 5 V USB-C charger + USB-C data cable (avoid USB-PD-only chargers) | 1 | €0 - €5 | Reuse existing charger |
| [ ] | **External Antenna** *(Optional)* | 868 MHz High-Gain SMA Antenna + U.FL-to-SMA Pigtail (for > 2 km range) | 1 | €6 - €9 | TinyTronics |

---

## 4. Calibration & Maintenance Supplies (Shared by Community Group)

| Status | Item | Specification | Approx. Cost | Suggested Suppliers |
| :--- | :--- | :--- | :---: | :--- |
| [ ] | **EC Calibration Fluid, high point** | Standard **1413 µS/cm** solution (250 ml) | €8 - €10 | Amazon.com.be or aquarium/hydroponics shop |
| [ ] | **EC Calibration Fluid, low point** | Standard **84 µS/cm** solution (250 ml), for a true two-point calibration | €8 - €10 | same |
| [ ] | **Multimeter** | To check boost voltage and battery voltage | €10+ | any |

---

## Buying Notes & Pitfalls to Avoid
* **Check LoRa frequency:** verify the Heltec V3 board is labelled **868 MHz** (Europe), not 915 MHz or 433 MHz.
* **Check TL-136 range & output:** choose **0-5 m** (or 0-4 m), **4-20 mA** and a **vented** cable. Do not buy the 0-10 V or RS485 versions; the firmware assumes a 4-20 mA loop. Check the minimum supply voltage (usually 9-12 V; the 18 V boost covers this).
* **Use a protected 18650:** the Heltec board charges the cell but has no deep-discharge cut-off.
* **Heat-shrink type matters:** ordinary thin-wall heat-shrink does not seal against water pressure. Look for **adhesive-lined** / **dual-wall** (*lijmgevuld* / *met lijmlaag*).
* **Shunt value:** the firmware default is **100 Ω**. If you use a different value, set `shunt_ohm` in the node file. 160 Ω also works with the ESP32 ADC as long as the water column stays below about 4.8 m (20 mA would give 3.2 V, above the ADC's usable range); see `docs/wiring.md`.
