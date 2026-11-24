# Waterproof cable splices for submerged probes

*Shared by `groundwater/` and `brook/lite/`. How long the extension must be is in the project's field guide.*

The TL-136 comes with a factory-sealed **vented** cable: **never cut or splice the TL-136 cable**, because that can block its internal atmospheric vent tube. Order it long enough to reach the enclosure.

The **DS18B20** and **EC probe** cables are only about 1 m long and usually need an extension with flexible waterproof rubber cable (such as 3 x 0.5 mm² H05RN-F):

* The **DS18B20** has three wires (`VCC`, `GND`, `Data`): all three cores are spliced. *(Tip: DS18B20 probes with a 5 m factory cable exist and avoid this splice.)*
* The **EC probe** is two stainless electrodes with **two wires**. Splice only those two (a twisted pair, or screened cable, is best because the signal is high-impedance). The module (`+ / - / A`) stays in the dry enclosure.

Because the splices sit underwater, use the **Marine Triple-Seal Method**.

## Materials
* **3:1 dual-wall adhesive-lined heat-shrink tubing** (marine-grade: it melts an internal hot-melt glue layer when heated; ordinary thin-wall heat-shrink does not seal against water pressure). Dutch: *lijmgevuld* / *met lijmlaag*.
* **Self-amalgamating silicone/rubber tape** (hardware stores such as Hubo or Brico).
* **Flexible rubber cable** for the extension.

## Step by step
1. **Slide tubing on first:** before soldering, slide one large outer piece of adhesive-lined heat-shrink (~10 cm long) onto the main extension cable, plus smaller pieces (~3 cm long) onto each individual inner wire.
2. **Stagger the cuts:** cut the inner wires at slightly staggered lengths (about 1.5 cm apart). This prevents a thick lump and ensures wires cannot short together.
3. **Solder & seal individual wires:** solder each wire pair cleanly, slide the small adhesive-lined heat-shrink over each joint, and shrink until a tiny ring of clear glue oozes out both ends.
4. **Wrap with self-amalgamating tape:** stretch the tape tightly around the entire staggered bundle, overlapping each turn by 50 % and extending 2 cm onto the original outer cable jackets. The tape fuses into a solid rubber block.
5. **Apply outer adhesive heat-shrink:** slide the large 10 cm tube over the rubber-wrapped joint and shrink it from the centre outward until hot-melt glue seals both ends onto the outer jackets.
6. **Submersion bucket test:** before installing the probes, coil the spliced sections in a bucket of tap water overnight and verify that the EC and temperature readings remain stable.
