#ifndef AUTOMATYK_PONG_UNO_PUSHCONTROLLER_HPP
#define AUTOMATYK_PONG_UNO_PUSHCONTROLLER_HPP

#include <Arduino.h>

namespace SNS {

template< uint8_t pinBtn, uint8_t pinSolenoid >
class PushController {
  inline static constexpr unsigned long delayPush = 100;

  inline static volatile unsigned long lastPushTime{ 0 };
  inline static volatile bool          isPushed{ false };
  inline static volatile bool          canPush{ true };

public:
  PushController() {
    attachInterrupt(pinToInterrupt<pinBtn>(), pushSolenoidCallback, FALLING);
  }

  // Call this in loop to preserve functionality
  void update() {
    if (isPushed && millis() - lastPushTime > delayPush / 2) {
      digitalWrite(pinSolenoid, LOW);
      isPushed = false;
    }

    if (!canPush && millis() - lastPushTime > delayPush) { canPush = true; }
  }

private:
  static void pushSolenoidCallback() {
    if (canPush) {
      digitalWrite(pinSolenoid, HIGH);
      lastPushTime = millis();
      isPushed     = true;
      canPush      = false;
    }
  }

  // Fix digitalPinToInterrupt from Arduino.h to preserve type of pin (uint8_t, not int)
  // This saves 2 bytes from binary size on debug and allows better optimizations on release
  // Compared to original Arduino.h which uses integer integrals inside the macro (integer integrals are int by default)
  // Added benefit of static_assert to check if pin supports interrupts
  template< auto pin >
  static constexpr auto pinToInterrupt() {
    static_assert(digitalPinToInterrupt(pin) != NOT_AN_INTERRUPT, "Pin does not support interrupts");
    return static_cast<uint8_t>(digitalPinToInterrupt(pin));
  }
};

} // namespace SNS

#endif // AUTOMATYK_PONG_UNO_PUSHCONTROLLER_HPP
