#include "Core.hpp"
#include <Arduino.h>

namespace SNS::Core {

void setup() {
  Serial.begin(9600);

  pinMode(pinBtnP1Push, INPUT_PULLUP);
  pinMode(pinBtnP1Left, INPUT_PULLUP);
  pinMode(pinBtnP1Right, INPUT_PULLUP);
  pinMode(pinBtnP2Push, INPUT_PULLUP);
  pinMode(pinBtnP2Left, INPUT_PULLUP);
  pinMode(pinBtnP2Right, INPUT_PULLUP);

  pinMode(pinSolenoidP1, OUTPUT);
  pinMode(pinSolenoidP2, OUTPUT);

  pinMode(pinMotorP1_1, OUTPUT);
  pinMode(pinMotorP1_2, OUTPUT);
  pinMode(pinMotorP1_3, OUTPUT);
  pinMode(pinMotorP1_4, OUTPUT);
  pinMode(pinMotorP2_1, OUTPUT);
  pinMode(pinMotorP2_2, OUTPUT);
  pinMode(pinMotorP2_3, OUTPUT);
  pinMode(pinMotorP2_4, OUTPUT);
}

} // namespace SNS::Core
