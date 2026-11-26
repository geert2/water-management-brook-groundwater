# Boost converter switch (P-MOSFET + 2N7000)

Used by `groundwater/` and `brook/lite/`. Firmware: [`shared/esphome/heltec-v3/boost-switch.yaml`](../esphome/heltec-v3/boost-switch.yaml) (`GPIO7`, output `boost_power`).

![Boost converter power switch](img/boost-switch.svg)

## Why

The TL-136 needs 18 V, made by an MT3608 boost converter. The 4-20 mA loop is the largest load of the node: 20 mA at 18 V is about 0.36 W, which at roughly 85 % efficiency (an assumption) is about 115 mA from a 3.7 V cell.

* Fed from `Vext`, that current runs through the Heltec's 3.3 V regulator and Vext switch, which also power the ESP32 and the radio, and whose current rating I could not confirm.
* Fed from the battery through its own switch, the boost converter is **on only while the level is read** (about 1 s per cycle), the battery is read **without** the loop load, and the EC probe is read while **no loop current** is present.

## Circuit

* `BAT+` to the P-MOSFET **source** (S).
* P-MOSFET **drain** (D) to the MT3608 `IN+`. The 220-470 µF capacitor goes across the MT3608 input (`IN+` to `GND`).
* P-MOSFET **gate** (G) to `BAT+` through **100 kΩ**, and to the **drain** of the N-MOSFET.
* N-MOSFET **source** to `GND`; its **gate** to `GPIO7` through **100 Ω**, with a **100 kΩ** pull-down from the gate to `GND`.

`GPIO7` HIGH: the N-MOSFET pulls the P-MOSFET gate low, and the battery reaches the boost converter. During deep sleep and reset the pin floats; the pull-down keeps everything off.

## Which parts

### P-MOSFET: two options
| Option | Part | Soldering | Where |
| :--- | :--- | :--- | :--- |
| **A, easiest** | **NDP6020P**, TO-220 | normal legs, straight into the perfboard | [TinyTronics](https://www.tinytronics.nl/en/components/ndp6020p-power-p-mosfet-20v-24a) |
| B | AO3401A, SOT-23 | tiny SMD part, needs an adapter board (below) | [Reichelt](https://reichelt.com/de/en/mosfet-p-ch-30v-4a-sot-23-ao-3401a-p166486.html) + [SOT-23-3 adapter](https://www.reichelt.com/de/en/shop/product/sot_23-3_adapter_0_95-mm_pitch_rm_2_54_mm-167706) |

Both are "logic level": they turn fully on with only about -2.5 to -3 V on the gate, which is all a nearly empty cell (3.0 V) gives. A common P-MOSFET such as the IRF9540, IRF5305 or IRF4905 does **not** (it needs -4 to -10 V) and would stay half on.

**NDP6020P legs** (TO-220, text facing you, legs pointing down): **G - D - S** from left to right; the metal tab is also D, so keep it from touching anything else. Check the datasheet of the part you bought. It is much bigger than needed (24 A), but that does no harm; it needs no heatsink at 0.1 A.

### N-MOSFET: 2N7000
* **2N7000** (TO-92, normal legs): fine here, it only pulls the 100 kΩ gate resistor low. With the flat side facing you and the legs pointing down, usually **S - G - D** (left to right). Check the datasheet of the part you bought.
* 2N7002 is the same part in SOT-23 (SMD); only use it if you already have an adapter.

### The P-MOSFET must turn fully on at a low battery
At 3.0 V the gate sees only about -3 V. If you substitute another P-MOSFET, pick one with `Rds(on)` specified at `Vgs = -2.5 V`.

## Option B: soldering the AO3401A (SOT-23) on an adapter

![SOT-23 adapter](img/sot23-adapter.svg)

Skip this section if you use the NDP6020P. The AO3401A only exists as a tiny SMD part (SOT-23, about 3 × 1.5 mm). An adapter board turns it into a part with normal 2.54 mm pins.

* **Simplest adapter:** a board with exactly **3 pads** for SOT-23-3, e.g. the [Roth SOT-23-3 adapter at Reichelt](https://www.reichelt.com/de/en/shop/product/sot_23-3_adapter_0_95-mm_pitch_rm_2_54_mm-167706): leg 1 on pad 1, leg 2 on pad 2, leg 3 on pad 3.

* Many cheap adapters are **double-sided**: one side has a 10-pin footprint (`SOP10` / `MSOP10`, `0.5MM`), the other side a 6-pad footprint marked `SOT23`, `SOT23-6` or `0.95MM`. The SOT-23 goes on **that** side.
* A SOT-23 has **3 legs**: two on one side (leg 1 = **G**, leg 2 = **S**), one alone on the other side (leg 3 = **D**). The AO3401A and 2N7002 both use this order.
* On a SOT23-6 footprint use **pad 1** (G), **pad 3** (S) and **pad 5** (D, the middle pad of the other row). Pads 2, 4 and 6 stay empty.
* Which hole each pad goes to differs between boards. **Follow the copper track or use a multimeter in continuity mode**, and write G / S / D next to the holes before you build.

Soldering, step by step:
1. Put a little solder on **one** pad (pad 1).
2. Hold the chip with tweezers on pads 1, 3 and 5, and reheat pad 1 so the leg sinks in.
3. Check the chip is straight, then solder the other two legs. A fine tip and flux help; a magnifier helps more.
4. Solder pin headers into the holes you need.
5. Check with the multimeter that G, S and D are **not** connected to each other (no solder bridge).

Bench test before connecting the TL-136: with `GPIO7` LOW (node asleep) the MT3608 `IN+` must read **0 V**; while the node measures it must read the battery voltage, and the MT3608 output **18.0 V**.
