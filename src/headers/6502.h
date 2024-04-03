#include <cstdint>
class Bus;

class C6502 {
public:
  C6502();
  ~C6502();

  void CconnectBus(Bus *n) { bus = n; };

public:
  enum FLAGS6502 {
    C = (1 << 0), // Carry Bit
    Z = (1 << 1), // Zero
    I = (1 << 2), // Disable Interrupts
    D = (1 << 3), // Decimal Mode (unused in this implementation) | Redundant
                  // because NES not use Decimal Mode in Hardware
    B = (1 << 4), // Break
    U = (1 << 5), // Unused
    V = (1 << 6), // Overflow
    N = (1 << 7), // Negative
  };

  // Register
  uint8_t a = 0x00;      // Accumulator Register
  uint8_t x = 0x00;      // X Register
  uint8_t y = 0x00;      // Y Register
  uint8_t stkp = 0x00;   // Stack Pointer (points to location on bus)
  uint16_t pc = 0x0000;  // Program Counter
  uint8_t status = 0x00; // Status Register

private:
  Bus *bus = nullptr;

  uint8_t read(uint16_t addr);
  void write(uint16_t addr, uint8_t data);

  uint8_t getFlag(FLAGS6502 f);
  void setFlag(FLAGS6502 f, bool v);
};
