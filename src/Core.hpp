#ifndef AUTOMATYK_PONG_UNO_CORE_HPP
#define AUTOMATYK_PONG_UNO_CORE_HPP

#include <Arduino.h>

namespace SNS::Core {

inline constexpr uint8_t pinBtnP1Push  = 2;
inline constexpr uint8_t pinBtnP1Left  = A0;
inline constexpr uint8_t pinBtnP1Right = A1;
inline constexpr uint8_t pinBtnP2Push  = 3;
inline constexpr uint8_t pinBtnP2Left  = A2;
inline constexpr uint8_t pinBtnP2Right = A3;

inline constexpr uint8_t pinSolenoidP1 = 4;
inline constexpr uint8_t pinSolenoidP2 = 5;

inline constexpr uint8_t pinMotorP1_1 = 6;
inline constexpr uint8_t pinMotorP1_2 = 7;
inline constexpr uint8_t pinMotorP1_3 = 8;
inline constexpr uint8_t pinMotorP1_4 = 9;
inline constexpr uint8_t pinMotorP2_1 = 10;
inline constexpr uint8_t pinMotorP2_2 = 11;
inline constexpr uint8_t pinMotorP2_3 = 12;
inline constexpr uint8_t pinMotorP2_4 = 13;

void setup();

} // namespace SNS::Core

#endif // AUTOMATYK_PONG_UNO_CORE_HPP
