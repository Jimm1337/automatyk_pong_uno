#ifndef AUTOMATYK_PONG_UNO_MOTORCONTROLLER_HPP
#define AUTOMATYK_PONG_UNO_MOTORCONTROLLER_HPP

#include <Arduino.h>
#include <Stepper.h>

namespace SNS {

class MotorController {
  inline static constexpr auto stepsPerRevolution = 200;
  inline static constexpr auto speed              = 240;

  Stepper stepper;
  uint8_t pinBtnLeft;
  uint8_t pinBtnRight;

public:
  MotorController(
    uint8_t pinBtnLeft,
    uint8_t pinBtnRight,
    uint8_t pinMotor1,
    uint8_t pinMotor2,
    uint8_t pinMotor3,
    uint8_t pinMotor4):
    stepper{ stepsPerRevolution, pinMotor1, pinMotor2, pinMotor3, pinMotor4 },
    pinBtnLeft{ pinBtnLeft },
    pinBtnRight{ pinBtnRight } {
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
