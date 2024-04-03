#include "headers/6502.h"

C6502::C6502() {}

C6502::~C6502() {}

uint8_t C6502::read(uint16_t addr) { return bus->read(addr, false); };

void C6502::write(uint16_t addr, uint8_t data) { bus->write(addr, data); };
