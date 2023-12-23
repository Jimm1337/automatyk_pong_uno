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
    attachInterrupt(
      digitalPinToInterrupt(pinBtn), pushSolenoidCallback, FALLING);
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
};

} // namespace SNS::PushController

#endif // AUTOMATYK_PONG_UNO_PUSHCONTROLLER_HPP
