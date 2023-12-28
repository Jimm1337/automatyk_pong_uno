#ifndef AUTOMATYK_PONG_UNO_MOTORCONTROLLER_HPP
#define AUTOMATYK_PONG_UNO_MOTORCONTROLLER_HPP

#include <Arduino.h>
#include <Stepper.h>

namespace SNS {

template< uint8_t pinBtnLeft, uint8_t pinBtnRight, uint8_t... pinsMotor >
class MotorController {
  inline static constexpr int  stepsPerRevolution = 200;
  inline static constexpr long speed              = 240;

  Stepper stepper;

public:
  MotorController(): stepper{ stepsPerRevolution, pinsMotor... } {
    stepper.setSpeed(speed);
  }

  // Call this in loop to preserve functionality
  void update() {
    const bool isLeftPressed  = digitalRead(pinBtnLeft) == LOW;
    const bool isRightPressed = digitalRead(pinBtnRight) == LOW;

    if (isLeftPressed && !isRightPressed) {
      stepper.step(-1);
    } else if (!isLeftPressed && isRightPressed) {
      stepper.step(1);
    }
  }
};

} // namespace SNS

#endif // AUTOMATYK_PONG_UNO_MOTORCONTROLLER_HPP
