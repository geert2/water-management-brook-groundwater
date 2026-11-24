// Shared calculations for the groundwater and brook stations.
// Included by shared/esphome/heltec-v3/node-base.yaml and shared/esphome/gateway/gateway-base.yaml,
// so every lambda in a node or gateway can call these functions.
#pragma once
#include <cmath>

// TL-136 4-20 mA transmitter: loop current (mA) from the voltage across the shunt resistor.
inline float tl136_loop_ma(float shunt_v, float shunt_ohm) {
  if (std::isnan(shunt_v)) return NAN;
  return shunt_v / shunt_ohm * 1000.0f;
}

// Water column above the TL-136 (m) from the loop current.
// Outside 3.5-22 mA means a broken wire, a short or a boost fault -> NAN.
// Readings more than 0.1 m below zero are treated as invalid -> NAN.
inline float tl136_column_m(float loop_ma, float range_m, float span_scale, float zero_offset_m) {
  if (std::isnan(loop_ma) || loop_ma < 3.5f || loop_ma > 22.0f) return NAN;
  float depth = (loop_ma - 4.0f) / 16.0f * range_m;
  depth = depth * span_scale + zero_offset_m;
  return depth < -0.1f ? NAN : depth;
}

// DFRobot SEN0244 analog TDS/EC sensor: EC at 25 C (uS/cm) from the module voltage [R19].
// Temperature compensation 2 %/C (12 C is used if the temperature is unknown), DFRobot's cubic
// TDS curve (TDS = EC / 2, so the 0.5 and 2.0 factors cancel), then the two-point calibration.
// The result is NOT clamped; the caller decides what to do with values below 0 or above the range.
inline float sen0244_ec25(float module_v, float temp_c, float gain, float offset) {
  if (std::isnan(module_v)) return NAN;
  if (std::isnan(temp_c)) temp_c = 12.0f;
  float v = module_v / (1.0f + 0.02f * (temp_c - 25.0f));
  float ec = 133.42f * v * v * v - 255.86f * v * v + 857.39f * v;
  return ec * gain + offset;
}
