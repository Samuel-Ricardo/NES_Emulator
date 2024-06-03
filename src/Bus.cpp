#include "./headers/Bus.h"
#include <cstdint>

Bus::Bus() {

  // clear ram
  for (auto &i : ram)
    i = 0X00;

  cpu.ConnectBus(this);
}

void Bus::write(uint16_t addr, uint8_t data) {

  // CHECK THE VALID RANGE OF ADDRESS
  if (addr >= 0x0000 && addr <= 0xFFFF)
    ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr, bool bReadOnly) {
  if (addr >= 0x0000 && addr <= 0xFFFF)
    ram[addr];

  return 0x00;
}
