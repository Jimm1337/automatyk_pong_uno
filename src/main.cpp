#include <Arduino.h>
#include "Core.hpp"
#include "MotorController.hpp"
#include "PushController.hpp"

void setup() {
  using namespace SNS;

  Core::setup();
}

[[maybe_unused]] void loop() {
  using namespace SNS;

  static PushController< Core::pinBtnP1Push, Core::pinSolenoidP1 > pushP1{};
  static PushController< Core::pinBtnP2Push, Core::pinSolenoidP2 > pushP2{};
  static MotorController<
    Core::pinBtnP1Left,
    Core::pinBtnP1Right,
    Core::pinMotorP1_1,
    Core::pinMotorP1_2,
    Core::pinMotorP1_3,
    Core::pinMotorP1_4 >
    motorP1{};
  static MotorController<
    Core::pinBtnP2Left,
    Core::pinBtnP2Right,
    Core::pinMotorP2_1,
    Core::pinMotorP2_2,
    Core::pinMotorP2_3,
    Core::pinMotorP2_4 >
    motorP2{};

  pushP1.update();
  pushP2.update();
  motorP1.update();
  motorP2.update();
}
