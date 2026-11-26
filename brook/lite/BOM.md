# Bill of Materials (BOM) & Sourcing Guide - BROOK LITE

> Brook lite station: water level (TL-136 0-2 m), water temperature (DS18B20), electrical conductivity (DFRobot SEN0244), air temperature, humidity and pressure (BME280). No ADS1115, turbidity, ultrasonic sensor or air-quality node (those are in `../full/`).

This checklist covers all hardware, waterproofing consumables, and gateway parts needed to build and deploy a brook lite station. Prices are approximate (including VAT) based on Benelux/EU electronics suppliers.

> **Shop links** were checked on 26 November 2026. Prices and stock change; Amazon/eBay listings especially can disappear or change seller, so check range, output (4-20 mA) and cable type before ordering. Links are examples, not endorsements; any equivalent part is fine.

---

## 1. Field Node at the Brook (~€110 - €150, plus ~€25 - €50 mounting)
One per measuring point. Electronics, sensors and enclosure come to about **€110 - €150**; the stilling pipe, conduit, post and pull line add about **€25 - €50**, and a staff gauge **€30 - €80** if there is none yet. With the gateway (section 3), the first station is about **€130** at the lower end of the price ranges (compare: groundwater ≈ €115, full brook station ≈ €190 without its air node).

| Status | Component | Exact Specification | Qty | Approx. Cost | Where to Buy (BE / NL / EU) |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Microcontroller** | Heltec WiFi LoRa 32 V3 (**868 MHz** EU version, ESP32-S3 + SX1262). Note the revision on the silkscreen (V3.0, V3.1 or V3.2): it decides the battery-divider polarity, see `docs/wiring.md` | 1 | €21 - €25 | [TinyTronics](https://www.tinytronics.nl/en/development-boards/microcontroller-boards/with-lora/heltec-wifi-lora-32-esp32-s3-sx1262-with-0.96-inch-oled-display) (~€21, often 2-4 weeks delivery), [Otronic](https://www.otronic.nl/en/heltec-wifi-lora-32v3-esp32s3-sx1262-lora-node-mes.html) (~€25) |
| [ ] | **Level Sensor** | TL-136 Submersible Level Transmitter (**0-2 m**, **4-20 mA**, **vented** cable long enough to reach the box, typically 5-10 m) | 1 | €25 - €35 | Amazon.de: [0-2 m](https://www.amazon.de/TL-136-Detektor-F%C3%BCllstandssensor-Wasserdichter-Fl%C3%BCssigkeitsstandsender/dp/B0CZLXZ8P2), [range selectable, 12-32 V](https://www.amazon.de/Fl%C3%BCssigkeitsstandsensor-Signalausgang-Wasserstandssensor-Edelstahl-Wasserstandsregler-Reichweite/dp/B08BLQVW26); [eBay 0-2 m](https://www.ebay.de/itm/396025445573); AliExpress |
| [ ] | **Temperature Probe** | Waterproof DS18B20 Digital Probe with **4-5 m** cable, so it reaches the box on the bank without a splice | 1 | €5 - €11 | [TinyTronics 4 m](https://www.tinytronics.nl/en/sensors/temperature/ds18b20-to-92-thermometer-temperature-sensor-with-cable-waterproof-high-temperature-4m), [Otronic 5 m](https://www.otronic.nl/en/ds18b20-waterproof-probe-temperature-sensor-5m-cable), [Kiwi 5 m + resistor](https://www.kiwi-electronics.com/en/waterproof-ds18b20-digital-temperature-sensor-plus-resistor-5-meter-3709) |
| [ ] | **Step-Up Boost Module** | MT3608 DC-DC Adjustable Step-Up Converter (set to **18.0 V**) | 1 | €2 | [TinyTronics](https://www.tinytronics.nl/en/power/voltage-converters/boost-(step-up)-converters/dc-dc-adjustable-step-up-boost-converter-mt3608-2a), [Otronic](https://www.otronic.nl/en/mt3608-2a-max-dc-dc-step-up-power-module-booster-power-module) |
| [ ] | **EC / Water Quality Sensor** | DFRobot **SEN0244** Gravity Analog TDS/EC Sensor Module + Probe (probe has **two** electrode wires) | 1 | €12 - €14 | [TinyTronics](https://www.tinytronics.nl/en/sensors/liquid/dfrobot-gravity-analog-tds-sensor), [BerryBase](https://www.berrybase.de/en/dfrobot-gravity-analogue-tds-sensor-probe-for-water-quality-measurement-0-1000-ppm-3.3-5.5v), [DFRobot](https://www.dfrobot.com/product-1662.html) |
| [ ] | **BME280 module** | BME280 breakout, 3.3 V, I²C (4 pins). Check it is a real BME280 (with humidity) and not a BMP280. | 1 | €4 - €6 | [TinyTronics](https://www.tinytronics.nl/en/sensors/air/pressure/bme280-digital-barometer-pressure-and-humidity-sensor-module), [Otronic](https://www.otronic.nl/en/3-in-1-sensor-temperature-humidity-and-air-pressure-3-3v-i2c-and-spi-bosch-bme280), [Gotron](https://www.gotron.be/bme280-temperatuur-luchtvochtigheid-en-luchtdruksensor.html) |
| [ ] | **Radiation shield** | Small louvred (Stevenson-type) sensor shield, or a DIY stack of white plant saucers; plus 4-core cable (≤ 1 m) and one extra cable gland | 1 | €8 - €15 | [Amazon.nl 10-plate shield](https://www.amazon.nl/thermometerhut-stralingsscherm-weerstation-geventileerde-stralingsschild/dp/B087QC6NC8), [Ambient Weather WH31-SRS](https://www.amazon.nl/Ambient-Weather-WH31-SRS-Zonnestralingsschild-Sensoren/dp/B09T4QDBN3), [AliExpress](https://www.aliexpress.com/w/wholesale-stevenson-screen.html), or DIY |
| [ ] | **Shunt Resistor** | **100 Ω** metal film, **0.1 %** (25 ppm), 0.25 W | 1 | €0.50 | [Reichelt](https://www.reichelt.com/de/en/shop/product/metal_film_resistor_100_ohm_axial_250_mw_0_1_-237001) (Welwyn RC55Y-100RB); Mouser/Farnell: search *RC55Y-100RB* or *100R 0.1 % 25 ppm* |
| [ ] | **Input Protection** | 1 kΩ resistor, **3.6 V zener** (e.g. BZX84C3V6 or 1N5227B), 100 nF ceramic capacitor | 1 set | €0.50 | Zener: [Gotron SMD 3V6](https://www.gotron.be/smd-z-diode-0-3w-3-6v-sot23.html) or [Gotron zener range](https://www.gotron.be/componenten/actief/zenerdioden.html); 1 kΩ: [TinyTronics resistor set](https://www.tinytronics.nl/en/resistor/10%CF%89-1m%CF%89-resistor-set) |
| [ ] | **Boost Input Capacitor** | 220 - 470 µF low-ESR electrolytic, ≥ 10 V | 1 | €0.50 | [Gotron 470 µF 16 V](https://www.gotron.be/electrolytic-capacitor-470-f-16v-8x11-5mm-105-c-p3-5.html), [Otronic 10× 470 µF 16 V](https://www.otronic.nl/en/10x-capacitor-470uf-16v-electrolytic-elco-black) |
| [ ] | **Pull-Up Resistor** | 4.7 kΩ resistor (0.25 W, for DS18B20 data line) | 1 | €0.10 | [TinyTronics resistor set](https://www.tinytronics.nl/en/resistor/10%CF%89-1m%CF%89-resistor-set) *(included with the Kiwi DS18B20)* |
| [ ] | **Batteries & Holder** | 2 × **protected** 18650 Li-Ion cells (3000 mAh+, e.g. Samsung 35E with protection), **in parallel**, + 2-cell holder wired in parallel (1S2P) | 2 | €16 - €24 | Cells: [NKON Keeppower 18650 3500 mAh protected, button top](https://www.nkon.nl/en/keeppower-18650-3500-li-ion.html) (~€10 each); holder: [TinyTronics 2× with wires per cell](https://www.tinytronics.nl/en/power/battery-holders-and-clips/18650/2x-18650-battery-holder-leaf-spring-contacts-wires-per-cell) (easiest to wire in parallel) or [2× button top](https://www.tinytronics.nl/en/power/battery-holders-and-clips/18650/2x-18650-battery-holder-with-loose-wires-button-top) |
| [ ] | **Waterproof Enclosure** | IP65 Outdoor Junction Box (approx. 150 x 110 x 70 mm) | 1 | €7 - €9 | [Gotron G313MF 171×121×55 IP65](https://www.gotron.be/waterbestendige-abs-behuizing-met-montageflens-donkergrijs-171x121x55mm.html), [TinyTronics Kradex 176×126×57 IP65](https://www.tinytronics.nl/en/tools-and-mounting/enclosures/universal/kradex-enclosure-176x126x57mm-ip65-grey-z74jh-tm-abs) |
| [ ] | **Enclosure Breather Vent** | M12 or PG7 membrane vent plug (IP67/IP68, e.g. Gore-type) for the TL-136 vent | 1 | €2 - €4 | Amazon.de: [Delock M12](https://www.amazon.de/Delock-Druckausgleichselement-M12-grau-St%C3%BCck/dp/B0B3HK9J13), [Fibox M12](https://www.amazon.de/GVPPA-M12L-Pressure-compensation-without-GVPPAM12L/dp/B01LYZS2LE), [Amphenol](https://www.amazon.de/-/en/PS1NGY-O8001-Pressure-Compensation-Device/dp/B07FK6PHRG) |
| [ ] | **Cable Glands** | **IP67/IP68** nylon cable glands, M12/M16 (match the cable diameter): TL-136, DS18B20, EC probe, BME280 | 4 | €2 | [TinyTronics M12 3-6.5 mm](https://www.tinytronics.nl/en/tools-and-mounting/installation-and-mounting-material/cable-glands/cable-gland-m12-3mm-6.5mm) (€0.60), [M16 6.5-8 mm](https://www.tinytronics.nl/en/tools-and-mounting/installation-and-mounting-material/cable-glands/cable-gland-m16-6.5mm-8mm), [M20 8-12 mm](https://www.tinytronics.nl/en/tools-and-mounting/installation-and-mounting-material/cable-glands/cable-gland-m20-8mm-12mm); [Gamma M20 IP68](https://www.gamma.be/nl/assortiment/wartel-m20-zwart-2-stuks/p/B606135) |
| [ ] | **Desiccant** | Silica Gel Packets (10 g-20 g) | 2 | €1 | Amazon.com.be: [wisedry 60 × 5 g](https://www.amazon.com.be/-/en/wisedry-Desiccant-Moisture-Indicator-Absorber/dp/B078WQ92V3), [25 × 20 g](https://www.amazon.com.be/-/nl/vochtindicator-regenereerbare-droogkristallen-levensmiddelen-herbruikbaar/dp/B0DD45NR4K) (colour indicator) |
| [ ] | **Assembly parts** | Perfboard or small PCB, screw terminals, hook-up wire, standoffs, cable ties | 1 set | €4 - €6 | Gotron, Hubo |
| [ ] | **Stilling pipe** | 40-50 mm PVC pipe (1.5-3 m, depending on the bank) with 8-10 mm holes every 5-10 cm, perforated end cap, 2-3 stainless pipe clamps + stakes | 1 | €10 - €20 | Hubo, Brico |
| [ ] | **Conduit** | Flexible corrugated conduit (20-25 mm) from the pipe to the box | 3-5 m | €4 - €8 | Hubo, Brico |
| [ ] | **Post** | Wooden or steel post for the box and radiation shield, standing above flood level | 1 | €8 - €15 | Hubo, Brico |
| [ ] | **Pull line** | 2-3 mm stainless wire or Kevlar line + clamp, to position the probe bundle in the pipe without pulling on the cables | 1 | €3 - €5 | Hubo, Brico |
| [ ] | **Staff gauge** *(if none exists)* | Enamelled water-level staff (peilschaal), 1-2 m, fixed to a post in the brook | 1 | €30 - €80 | [TopEmaille enamel staff, 115 cm](https://www.qualityenamelsigns.co.uk/emaille-peilschaal-standaard-peilschaal) (~€80); or a DIY ruler on a post |

*Optional range:* external 868 MHz antenna with bulkhead SMA pigtail (€6 - €9).

---

## 2. Submersible Cable Waterproofing (~€10, Shared Across Multiple Nodes)
Needed to extend the short factory cables on the EC and DS18B20 probes to the box on the bank (typically 3-5 m).

| Status | Item | Specification | Qty | Approx. Cost | Where to Buy |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Extension Cable** | Flexible waterproof rubber cable (H05RN-F, 3 x 0.5 mm²). The DS18B20 uses all three cores; the EC probe uses **two** (twisted pair or screened is better). | 8 m | €6 - €8 | Hubo, Brico |
| [ ] | **Adhesive Heat-Shrink** | **3:1 Dual-Wall Marine Adhesive-Lined** Heat-Shrink Tubing (3 mm & 10 mm) | 1 pack | €5 | [Gotron heat-shrink, *met lijm* subcategory](https://www.gotron.be/installatie/kabels/krimpkous.html), Amazon.com.be |
| [ ] | **Rubber Sealing Tape** | Self-Amalgamating Silicone/Rubber Tape | 1 roll | €5 | [Gotron HPX 25 mm × 3 m](https://www.gotron.be/hpx-stretch-fuse-tape-black-25mm-x3m.html), [Brico Nowlinq 20 mm × 10 m](https://www.brico.be/nl/ijzerwaren/lijmen-tapes-reparatiekits/tapes/overige-tapes/nowlinq-vulcaniserende-tape-10-meter/10418891) |
| [ ] | **Cable Ties** | UV-Resistant Black Nylon Zip Ties | 1 pack | €2 | Hubo, Brico |

---

## 3. Gateway at Home (~€21 - €30, One-Time Purchase)
The gateway receives the LoRa packets and uploads them to Home Assistant and openSenseMap. It is separate from the gateway of the full station in `../full/` (different firmware).

| Status | Component | Exact Specification | Qty | Approx. Cost | Where to Buy |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Gateway Board** | Heltec WiFi LoRa 32 V3 (**868 MHz** EU version) | 1 | €21 - €25 | [TinyTronics](https://www.tinytronics.nl/en/development-boards/microcontroller-boards/with-lora/heltec-wifi-lora-32-esp32-s3-sx1262-with-0.96-inch-oled-display) (~€21, often 2-4 weeks delivery), [Otronic](https://www.otronic.nl/en/heltec-wifi-lora-32v3-esp32s3-sx1262-lora-node-mes.html) (~€25) |
| [ ] | **Power Supply** | Plain 5 V USB-C charger + USB-C data cable (avoid USB-PD-only chargers) | 1 | €0 - €5 | Reuse existing charger |
| [ ] | **External Antenna** *(Optional)* | 868 MHz High-Gain SMA Antenna + U.FL-to-SMA Pigtail (for > 2 km range) | 1 | €6 - €9 | [Kiwi Electronics 868 MHz SMA 2.8 dBi](https://www.kiwi-electronics.com/en/2-8dbi-lora-antenna-sma-male-868mhz-195mm-20047) + U.FL-to-SMA pigtail |

---

## 4. Calibration & Maintenance Supplies (Shared by Community Group)

| Status | Item | Specification | Approx. Cost | Where to Buy |
| :--- | :--- | :--- | :---: | :--- |
| [ ] | **Multimeter** | To check boost voltage and battery voltage | €10+ | any |
| [ ] | **Handheld EC meter** *(optional)* | To check the EC sensor in the brook every few months | €15 - €40 | aquarium/hydroponics shop |
| [ ] | **Waders or boots, gloves** | Safe work at the bank | - | - |
| [ ] | **Reference thermometer / hygrometer** *(optional)* | To sanity-check the BME280 and DS18B20 | €10 - €20 | any |
| [ ] | **EC Calibration Fluid, high point** | Standard **1413 µS/cm** solution (250 ml) | €8 - €10 | Hanna HI70031P (25 × 20 ml sachets): [RS](https://ie.rs-online.com/web/p/products/4848755), [CPC Farnell](https://cpc.farnell.com/hanna-instruments/hi-70031p/calibration-sachet-ec-1413us/dp/IN07131) |
| [ ] | **EC Calibration Fluid, low point** | Standard **84 µS/cm** solution (250 ml), for a true two-point calibration | €8 - €10 | [Hanna HI7033/1L](https://hannainst.com/hi7033-1l.html) (84 µS/cm; the HI70033P sachets are discontinued at RS) |

---

## Buying Notes & Pitfalls to Avoid
* **Check LoRa frequency:** verify the Heltec V3 board is labelled **868 MHz** (Europe), not 915 MHz or 433 MHz.
* **Check TL-136 range & output:** choose **0-2 m**, **4-20 mA** and a **vented** cable. A 0-2 m sensor resolves the level much better than a 0-5 m one; floods above 2 m are flagged but not measured. Do not buy the 0-10 V or RS485 versions; the firmware assumes a 4-20 mA loop. Check the supply range on the label (listed as 12-32 V [R21]; the 18 V boost covers this).
* **BME280 vs BMP280:** the BMP280 has no humidity sensor. Look for "BME280" on the chip (square metal can with a hole) and in the listing; many cheap listings mix them up.
* **EC sensor range:** the cheap analog EC/TDS sensor is meant for fresh water up to about 2000 µS/cm. It is fine for seeing storm dilution, discharges or fertilizer run-off as trends, not for lab-grade numbers.
* **Use a protected 18650:** the Heltec board charges the cell but has no deep-discharge cut-off.
* **Heat-shrink type matters:** ordinary thin-wall heat-shrink does not seal against water pressure. Look for **adhesive-lined** / **dual-wall** (*lijmgevuld* / *met lijmlaag*).
* **Shunt value:** use **100 Ω**. The 160 Ω of the full station only works with its ADS1115 (see `docs/wiring.md`).
* **Permission:** ask the waterway manager before fixing a pipe, post or staff gauge in or on the bank.
* **Cable glands:** many DIY-store glands (e.g. PG11 at Brico) are only **IP54**. Use IP67/IP68 glands sized to the cable.
* **Long DS18B20 cable:** a probe with a 4-6 m factory cable avoids the underwater splice; the extension cable and heat-shrink in section 2 are then only needed for the EC probe.
