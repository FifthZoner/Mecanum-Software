#ifndef MOTOR_POWER_HPP
#define MOTOR_POWER_HPP

#include <stdint.h>

// structure for handling current motor movement directions
struct motorPower {

  uint8_t frontRightForward = 0;
  uint8_t frontLeftForward = 0;
  uint8_t backRightForward = 0;
  uint8_t backLeftForward = 0;
  uint8_t frontRightBackward = 0;
  uint8_t frontLeftBackward = 0;
  uint8_t backRightBackward = 0;
  uint8_t backLeftBackward = 0;

  motorPower(void);

  // give motor power in the same order as in structure
  motorPower(uint8_t frf, uint8_t flf, uint8_t brf, uint8_t blf, uint8_t frb, uint8_t flb, uint8_t brb, uint8_t blb);

  motorPower operator+(motorPower const& obj);

  void operator+=(motorPower const& obj);

  motorPower operator-(motorPower const& obj);

  motorPower operator*(float const& multiplier);
};

// applies the given values to the real motors
void setMotorPower(struct motorPower values);

void delayBypass(uint16_t time);

// pin numbers for motors
// change if physical pin layout changed
#define FRONT_RIGHT_FORWARD 2
#define FRONT_LEFT_FORWARD 3
#define BACK_RIGHT_FORWARD 9
#define BACK_LEFT_FORWARD 8
#define FRONT_RIGHT_BACKWARD 6
#define FRONT_LEFT_BACKWARD 7
#define BACK_RIGHT_BACKWARD 5
#define BACK_LEFT_BACKWARD 4

#endif