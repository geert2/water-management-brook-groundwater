# Bill of Materials (BOM) & Sourcing Guide

This checklist covers all hardware, waterproofing consumables, and gateway parts needed to build and deploy a groundwater monitoring station. Prices are approximate (including VAT) based on Benelux/EU electronics suppliers.

> **Shop links** were checked on 26 November 2026. Prices and stock change; Amazon/eBay listings especially can disappear or change seller, so check range, output (4-20 mA) and cable type before ordering. Links are examples, not endorsements; any equivalent part is fine.

---

## 1. Per-Well Field Node (~€90 - €110)
Build one of these units for each observation well (piezometer) you want to monitor.

| Status | Component | Exact Specification | Qty | Approx. Cost | Where to Buy (BE / NL / EU) |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Microcontroller** | Heltec WiFi LoRa 32 V3 (**868 MHz** EU version, ESP32-S3 + SX1262). Note the revision on the silkscreen (V3.0, V3.1 or V3.2): it decides the battery-divider polarity, see `docs/wiring.md` | 1 | €21 - €25 | [TinyTronics](https://www.tinytronics.nl/en/development-boards/microcontroller-boards/with-lora/heltec-wifi-lora-32-esp32-s3-sx1262-with-0.96-inch-oled-display) (~€21, often 2-4 weeks delivery), [Otronic](https://www.otronic.nl/en/heltec-wifi-lora-32v3-esp32s3-sx1262-lora-node-mes.html) (~€25) |
| [ ] | **Depth Sensor** | TL-136 Submersible Level Transmitter (**0-5 m**, **4-20 mA**, 5 m+ **vented** cable) | 1 | €25 - €35 | Amazon.de: [0-5 m](https://www.amazon.de/TL-Fl%C3%BCssigkeitsstandsender-%C3%96lstandsensor-Detektor-Signalausgang/dp/B08YX7DQ95), [range selectable, 12-32 V](https://www.amazon.de/Fl%C3%BCssigkeitsstandsensor-Signalausgang-Wasserstandssensor-Edelstahl-Wasserstandsregler-Reichweite/dp/B08BLQVW26); AliExpress |
| [ ] | **EC / Water Quality Sensor** | DFRobot Gravity Analog TDS/EC Sensor Module + Probe (probe has **two** electrode wires) | 1 | €12 - €14 | [TinyTronics](https://www.tinytronics.nl/en/sensors/liquid/dfrobot-gravity-analog-tds-sensor), [BerryBase](https://www.berrybase.de/en/dfrobot-gravity-analogue-tds-sensor-probe-for-water-quality-measurement-0-1000-ppm-3.3-5.5v), [DFRobot](https://www.dfrobot.com/product-1662.html) |
| [ ] | **Temperature Probe** | Waterproof DS18B20 Digital Probe with **5-6 m** cable, so it reaches the box without a splice | 1 | €5 - €11 | [TinyTronics 6 m](https://www.tinytronics.nl/en/sensors/temperature/ds18b20-temperature-sensor-with-cable-waterproof-6m), [Otronic 5 m](https://www.otronic.nl/en/ds18b20-waterproof-probe-temperature-sensor-5m-cable), [Kiwi 5 m + resistor](https://www.kiwi-electronics.com/en/waterproof-ds18b20-digital-temperature-sensor-plus-resistor-5-meter-3709) |
| [ ] | **Step-Up Boost Module** | MT3608 DC-DC Adjustable Step-Up Converter (set to **18.0 V**) | 1 | €2 | [TinyTronics](https://www.tinytronics.nl/en/power/voltage-converters/boost-(step-up)-converters/dc-dc-adjustable-step-up-boost-converter-mt3608-2a), [Otronic](https://www.otronic.nl/en/mt3608-2a-max-dc-dc-step-up-power-module-booster-power-module) |
| [ ] | **BME280 module** *(optional)* | BME280 breakout, 3.3 V, I²C (4 pins). Check it is a real BME280 (with humidity) and not a BMP280. | 1 | €4 - €6 | [TinyTronics](https://www.tinytronics.nl/en/sensors/air/pressure/bme280-digital-barometer-pressure-and-humidity-sensor-module), [Otronic](https://www.otronic.nl/en/3-in-1-sensor-temperature-humidity-and-air-pressure-3-3v-i2c-and-spi-bosch-bme280), [Gotron](https://www.gotron.be/bme280-temperatuur-luchtvochtigheid-en-luchtdruksensor.html) |
| [ ] | **Shunt Resistor** | **100 Ω** (or 160 Ω, see `docs/wiring.md`) metal film, **0.1 %** (25 ppm), 0.25 W | 1 | €0.50 | [Reichelt RC55Y-100RB](https://www.reichelt.com/de/en/shop/product/metal_film_resistor_100_ohm_axial_250_mw_0_1_-237001); see *Small parts shopping list* |
| [ ] | **Input Protection** | 1 kΩ resistor, **3.6 V zener** (e.g. BZX84C3V6 or 1N5227B), 100 nF ceramic capacitor | 1 set | €0.50 | Zener: [Reichelt BZX79C3V6](https://www.reichelt.com/de/en/zener-diode-0-5-w-3-6-v-zf-3-6-p23127.html); 1 kΩ: Otronic [10× 1 kΩ](https://www.otronic.nl/nl/10x-weerstand-1k-ohm-1-4-watt-5.html); 100 nF: Otronic [100 nF 50 V ceramic](https://www.otronic.nl/en/ceramic-disc-capacitor-104-50v-01uf-100nf-10.html) |
| [ ] | **Boost power switch** | AO3401A P-MOSFET (SOT-23, on an adapter board), 2N7002 (SOT-23) or 2N7000 (TO-92) N-MOSFET, 2 x 100 kΩ, 1 x 100 Ω (0.25 W). Switches the MT3608 input from the battery. How to solder the SOT-23 part: [boost-switch.md](../shared/docs/boost-switch.md) | 1 set | €1 | [Reichelt AO3401A](https://reichelt.com/de/en/mosfet-p-ch-30v-4a-sot-23-ao-3401a-p166486.html) + [SOT-23 adapter](https://www.tinytronics.nl/en/tools-and-mounting/prototyping-supplies/breakout-boards); [TinyTronics 2N7000](https://www.tinytronics.nl/en/switches/transistors-and-mosfets/mosfets-fets/2n7000-fet-60v-200ma); resistors: Otronic [10× 100 kΩ](https://www.otronic.nl/en/10x-resistor-100k-ohm-1-4-watt-5.html), [10× 100 Ω](https://www.otronic.nl/en/10x-resistor-100-ohm-1-4-watt-5.html) |
| [ ] | **Boost Input Capacitor** | 220 - 470 µF low-ESR electrolytic, ≥ 10 V | 1 | €0.50 | [Gotron 470 µF 16 V](https://www.gotron.be/electrolytic-capacitor-470-f-16v-8x11-5mm-105-c-p3-5.html), [Otronic 10× 470 µF 16 V](https://www.otronic.nl/en/10x-capacitor-470uf-16v-electrolytic-elco-black) |
| [ ] | **Pull-Up Resistor** | 4.7 kΩ resistor (0.25 W, for DS18B20 data line) | 1 | €0.10 | Otronic [10× 4.7 kΩ](https://www.otronic.nl/en/10x-resistance-4k7-ohm-1-4-watt-5.html) *(included with the Kiwi DS18B20)* |
| [ ] | **Battery & Holder** | **Protected** 18650 Li-Ion cell (3000 mAh+, e.g. Samsung 35E with protection) + 1x 18650 holder | 1 | €8 - €12 | Cell: [NKON Keeppower 18650 3500 mAh protected, button top](https://www.nkon.nl/en/keeppower-18650-3500-li-ion.html) (~€10); holder: [TinyTronics 18650 holders](https://www.tinytronics.nl/en/power/battery-holders-and-clips/18650) (pick one that fits a ~69 mm protected cell) |
| [ ] | **Waterproof Enclosure** | IP65 Outdoor Junction Box (approx. 150 x 110 x 70 mm) | 1 | €7 - €9 | [Gotron G313MF 171×121×55 IP65](https://www.gotron.be/waterbestendige-abs-behuizing-met-montageflens-donkergrijs-171x121x55mm.html), [TinyTronics Kradex 176×126×57 IP65](https://www.tinytronics.nl/en/tools-and-mounting/enclosures/universal/kradex-enclosure-176x126x57mm-ip65-grey-z74jh-tm-abs) |
| [ ] | **Enclosure Breather Vent** | M12 or PG7 membrane vent plug (IP67/IP68, e.g. Gore-type) for the TL-136 vent | 1 | €2 - €4 | Amazon.de: [Delock M12](https://www.amazon.de/Delock-Druckausgleichselement-M12-grau-St%C3%BCck/dp/B0B3HK9J13), [Fibox M12](https://www.amazon.de/GVPPA-M12L-Pressure-compensation-without-GVPPAM12L/dp/B01LYZS2LE), [Amphenol](https://www.amazon.de/-/en/PS1NGY-O8001-Pressure-Compensation-Device/dp/B07FK6PHRG) |
| [ ] | **Cable Glands** | **IP67/IP68** nylon cable glands, M12/M16 (match the cable diameter) | 3 | €2 | [TinyTronics M12 3-6.5 mm](https://www.tinytronics.nl/en/tools-and-mounting/installation-and-mounting-material/cable-glands/cable-gland-m12-3mm-6.5mm) (€0.60), [M16 6.5-8 mm](https://www.tinytronics.nl/en/tools-and-mounting/installation-and-mounting-material/cable-glands/cable-gland-m16-6.5mm-8mm), [M20 8-12 mm](https://www.tinytronics.nl/en/tools-and-mounting/installation-and-mounting-material/cable-glands/cable-gland-m20-8mm-12mm); [Gamma M20 IP68](https://www.gamma.be/nl/assortiment/wartel-m20-zwart-2-stuks/p/B606135) |
| [ ] | **Desiccant** | Silica Gel Packets (10 g-20 g) | 2 | €1 | Amazon.com.be: [wisedry 60 × 5 g](https://www.amazon.com.be/-/en/wisedry-Desiccant-Moisture-Indicator-Absorber/dp/B078WQ92V3), [25 × 20 g](https://www.amazon.com.be/-/nl/vochtindicator-regenereerbare-droogkristallen-levensmiddelen-herbruikbaar/dp/B0DD45NR4K) (colour indicator) |
| [ ] | **Assembly parts** | Perfboard or small PCB, screw terminals, hook-up wire, standoffs, cable ties | 1 set | €4 - €6 | Otronic: [perfboard 7×9 cm double-sided](https://www.otronic.nl/nl/experimenteer-prototyping-printplaat-7x9cm-groen.html), [2-way screw terminal KF301 5 mm](https://www.otronic.nl/en/screw-terminal-2-way-straight-kf301-2p-5mm.html), [22AWG solid wire, red](https://www.otronic.nl/en/rode-draad-met-massieve-kern-22awg-voor-breadboard.html) / [black](https://www.otronic.nl/en/zwarte-draad-met-massieve-kern-22awg-voor-breadboa.html) (per metre) |
| [ ] | **Hanging line** | 2-3 mm stainless wire or Kevlar line (≥ 5 m) + clamp, so the probe bundle does not hang from its cables | 1 | €3 - €5 | Hubo, Brico |
| [ ] | **Manual dip meter** *(shared)* | Beeper tape/dip meter or a weighted tape measure, for cross-checking depth | 1 per group | €15 - €40 | Hydro suppliers, e.g. [Royal Eijkelkamp dip meters (brochure)](https://www.royaleijkelkamp.com/media/thspp4yc/peilapparaten_1103n.pdf); Amazon.com.be |

*Optional accuracy upgrade:* **ADS1115** 16-bit I²C ADC module (€3 - €5) for the depth channel; see `docs/wiring.md`. *Optional range:* external 868 MHz antenna with bulkhead SMA pigtail (€6 - €9).


### Small parts shopping list

The small parts are the hardest to find, so here they are as exact product pages. With **two orders** you have everything: one at **Reichelt** for the special parts (0.1 % shunt, zener, AO3401A) and one at **Otronic** for the common ones. Otronic sells resistors in bags of 10, so one order covers several nodes. Prices are a few cents to about €1.50 per item.

| Status | Part | Qty per node | Exact product |
| :--- | :--- | :---: | :--- |
| [ ] | Shunt resistor 100 Ω **0.1 %**, 25 ppm | 1 | Reichelt: [Welwyn RC55Y-100RB](https://www.reichelt.com/de/en/shop/product/metal_film_resistor_100_ohm_axial_250_mw_0_1_-237001) |
| [ ] | Zener diode **3.6 V**, 0.5 W, DO-35 (BZX79C3V6) | 1-2 | Reichelt: [BZX79C3V6](https://www.reichelt.com/de/en/zener-diode-0-5-w-3-6-v-zf-3-6-p23127.html) |
| [ ] | P-MOSFET **AO3401A**, SOT-23 | 1 | Reichelt: [AO3401A](https://reichelt.com/de/en/mosfet-p-ch-30v-4a-sot-23-ao-3401a-p166486.html) |
| [ ] | N-MOSFET 2N7002 (SOT-23) **or 2N7000** (TO-92, easier on perfboard; legs with the flat side facing you: **S - G - D**, check the datasheet) | 1 | TinyTronics: [2N7000](https://www.tinytronics.nl/en/switches/transistors-and-mosfets/mosfets-fets/2n7000-fet-60v-200ma) |
| [ ] | SOT-23 to DIP adapter, for the AO3401A on perfboard | 1 | TinyTronics: [SOT-23 breakout boards](https://www.tinytronics.nl/en/tools-and-mounting/prototyping-supplies/breakout-boards) |
| [ ] | Resistor 100 kΩ, 1/4 W | 2 | Otronic: [10× 100 kΩ](https://www.otronic.nl/en/10x-resistor-100k-ohm-1-4-watt-5.html) |
| [ ] | Resistor 100 Ω, 1/4 W (MOSFET gate) | 1 | Otronic: [10× 100 Ω](https://www.otronic.nl/en/10x-resistor-100-ohm-1-4-watt-5.html) |
| [ ] | Resistor 1 kΩ, 1/4 W (ADC input) | 1 | Otronic: [10× 1 kΩ](https://www.otronic.nl/nl/10x-weerstand-1k-ohm-1-4-watt-5.html) |
| [ ] | Resistor 4.7 kΩ, 1/4 W (DS18B20 pull-up) | 1 | Otronic: [10× 4.7 kΩ](https://www.otronic.nl/en/10x-resistance-4k7-ohm-1-4-watt-5.html) |
| [ ] | Ceramic capacitor 100 nF (ADC input) | 1 | Otronic: [100 nF 50 V ceramic](https://www.otronic.nl/en/ceramic-disc-capacitor-104-50v-01uf-100nf-10.html) |
| [ ] | Electrolytic capacitor 470 µF 16 V (boost input) | 1 | Otronic: [10× 470 µF 16 V](https://www.otronic.nl/en/10x-capacitor-470uf-16v-electrolytic-elco-black) |
| [ ] | Screw terminals, 2-way 5 mm (TL-136, DS18B20, EC, battery) | 4-6 | Otronic: [2-way screw terminal KF301 5 mm](https://www.otronic.nl/en/screw-terminal-2-way-straight-kf301-2p-5mm.html) |
| [ ] | Perfboard | 1 | Otronic: [perfboard 7×9 cm double-sided](https://www.otronic.nl/nl/experimenteer-prototyping-printplaat-7x9cm-groen.html) |
| [ ] | Hook-up wire | 2 m | Otronic: [22AWG solid wire, red](https://www.otronic.nl/en/rode-draad-met-massieve-kern-22awg-voor-breadboard.html) / [black](https://www.otronic.nl/en/zwarte-draad-met-massieve-kern-22awg-voor-breadboa.html) (per metre) |

*Tip:* Gotron (Belgium) also stocks the BZX79C3V6 zener in its shop and catalogue; ask at the counter if you prefer to pick it up.

---

## 2. Submersible Cable Waterproofing (~€10, Shared Across Multiple Nodes)
Needed to extend the short factory cables on the EC and DS18B20 probes down to 4.5 metres.

| Status | Item | Specification | Qty | Approx. Cost | Where to Buy |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Extension Cable** | Flexible waterproof rubber cable (H05RN-F, 3 x 0.5 mm²). The DS18B20 uses all three cores; the EC probe uses **two** (twisted pair or screened is better). | 8 m | €6 - €8 | Hubo, Brico |
| [ ] | **Adhesive Heat-Shrink** | **3:1 Dual-Wall Marine Adhesive-Lined** Heat-Shrink Tubing (3 mm & 10 mm) | 1 pack | €5 | [Gotron heat-shrink, *met lijm* subcategory](https://www.gotron.be/installatie/kabels/krimpkous.html), Amazon.com.be |
| [ ] | **Rubber Sealing Tape** | Self-Amalgamating Silicone/Rubber Tape | 1 roll | €5 | [Gotron HPX 25 mm × 3 m](https://www.gotron.be/hpx-stretch-fuse-tape-black-25mm-x3m.html), [Brico Nowlinq 20 mm × 10 m](https://www.brico.be/nl/ijzerwaren/lijmen-tapes-reparatiekits/tapes/overige-tapes/nowlinq-vulcaniserende-tape-10-meter/10418891) |
| [ ] | **Cable Ties** | UV-Resistant Black Nylon Zip Ties | 1 pack | €2 | Hubo, Brico |

---

## 3. Central Farmhouse Gateway (~€21 - €30, One-Time Purchase)
One gateway receives LoRa packets from all neighbouring wells and uploads them to Home Assistant and openSenseMap.

| Status | Component | Exact Specification | Qty | Approx. Cost | Where to Buy |
| :--- | :--- | :--- | :---: | :---: | :--- |
| [ ] | **Gateway Board** | Heltec WiFi LoRa 32 V3 (**868 MHz** EU version) | 1 | €21 - €25 | [TinyTronics](https://www.tinytronics.nl/en/development-boards/microcontroller-boards/with-lora/heltec-wifi-lora-32-esp32-s3-sx1262-with-0.96-inch-oled-display) (~€21, often 2-4 weeks delivery), [Otronic](https://www.otronic.nl/en/heltec-wifi-lora-32v3-esp32s3-sx1262-lora-node-mes.html) (~€25) |
| [ ] | **Power Supply** | Plain 5 V USB-C charger + USB-C data cable (avoid USB-PD-only chargers) | 1 | €0 - €5 | Reuse existing charger |
| [ ] | **External Antenna** *(Optional)* | 868 MHz High-Gain SMA Antenna + U.FL-to-SMA Pigtail (for > 2 km range) | 1 | €6 - €9 | [Kiwi Electronics 868 MHz SMA 2.8 dBi](https://www.kiwi-electronics.com/en/2-8dbi-lora-antenna-sma-male-868mhz-195mm-20047) + U.FL-to-SMA pigtail |

---

## 4. Calibration & Maintenance Supplies (Shared by Community Group)

| Status | Item | Specification | Approx. Cost | Where to Buy |
| :--- | :--- | :--- | :---: | :--- |
| [ ] | **EC Calibration Fluid, high point** | Standard **1413 µS/cm** solution (250 ml) | €8 - €10 | Hanna HI70031P (25 × 20 ml sachets): [RS](https://ie.rs-online.com/web/p/products/4848755), [CPC Farnell](https://cpc.farnell.com/hanna-instruments/hi-70031p/calibration-sachet-ec-1413us/dp/IN07131) |
| [ ] | **EC Calibration Fluid, low point** | Standard **84 µS/cm** solution (250 ml), for a true two-point calibration | €8 - €10 | [Hanna HI7033/1L](https://hannainst.com/hi7033-1l.html) (84 µS/cm; the HI70033P sachets are discontinued at RS) |
| [ ] | **Multimeter** | To check boost voltage and battery voltage | €10+ | any |

---

## Buying Notes & Pitfalls to Avoid
* **Check LoRa frequency:** verify the Heltec V3 board is labelled **868 MHz** (Europe), not 915 MHz or 433 MHz.
* **Check TL-136 range & output:** choose **0-5 m** (or 0-4 m), **4-20 mA** and a **vented** cable. Do not buy the 0-10 V or RS485 versions; the firmware assumes a 4-20 mA loop. Check the minimum supply voltage (usually 9-12 V; the 18 V boost covers this).
* **Use a protected 18650:** the Heltec board charges the cell but has no deep-discharge cut-off.
* **Heat-shrink type matters:** ordinary thin-wall heat-shrink does not seal against water pressure. Look for **adhesive-lined** / **dual-wall** (*lijmgevuld* / *met lijmlaag*).
* **Shunt value:** the firmware default is **100 Ω**. If you use a different value, set `wN_shunt_ohm` in the gateway file (the calibration lives in the gateway). 160 Ω also works with the ESP32 ADC as long as the water column stays below about 4.8 m (20 mA would give 3.2 V, above the ADC's usable range); see `docs/wiring.md`.
* **Cable glands:** many DIY-store glands (e.g. PG11 at Brico) are only **IP54**. Use IP67/IP68 glands sized to the cable.
* **Long DS18B20 cable:** a probe with a 4-6 m factory cable avoids the underwater splice; the extension cable and heat-shrink in section 2 are then only needed for the EC probe.
