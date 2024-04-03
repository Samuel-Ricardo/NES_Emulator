#include <cstdint>
class Bus;

class C6502 {
public:
  C6502();
  ~C6502();

  void CconnectBus(Bus *n) { bus = n; };

private:
  Bus *bus = nullptr;

  uint8_t read(uint16_t addr);
  void write(uint16_t addr, uint8_t data);
};
