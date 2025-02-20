#pragma once
#include <limits.h>

#include <cstdint>

// merand48 copied from VW. Stable random number generator for reproducibility
constexpr uint64_t CONSTANT_A = 0xeece66d5deece66dULL;
constexpr uint64_t CONSTANT_C = 2147483647;

constexpr int BIAS = 127 << 23;

// int-ified version of merand48...
inline float rand48(uint64_t& initial)
{
  static_assert(
      sizeof(int32_t) == sizeof(float), "Floats and int32_ts are converted between, they must be the same size.");
  initial = CONSTANT_A * initial + CONSTANT_C;
  int32_t temp = ((initial >> 25) & 0x7FFFFF) | BIAS;
  return reinterpret_cast<float&>(temp) - 1;
}