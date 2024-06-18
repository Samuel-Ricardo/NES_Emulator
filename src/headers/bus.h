#pragma once
#include "6502.h"
#include <array>
#include <cstdint>

class Bus {
public:
  Bus();
  ~Bus();

public: // Devices on BUS
  C6502 cpu;

  // Fake RAM for this part of the series;
  std::array<uint8_t, 64 * 1024> ram;

public:
  void write(uint16_t addr, uint8_t data);
  uint8_t read(uint16_t addr, bool bReadOnly = false);
};
