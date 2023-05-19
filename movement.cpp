#include "movement.hpp"
#include "motorPower.hpp"

struct motorPower driveFrontLeft(uint8_t power) {
  return motorPower(power, 0, 0, power, 0, 0, 0, 0);
}

struct motorPower driveFrontRight(uint8_t power) {
  return motorPower(0, power, power, 0, 0, 0, 0, 0);
}

struct motorPower driveBackRight(uint8_t power) {
  return motorPower(0, 0, 0, 0, power, 0, 0, power);
}

struct motorPower driveBackLeft(uint8_t power) {
  return motorPower(0, 0, 0, 0, 0, power, power, 0);
}

struct motorPower driveFront(uint8_t power) {
  return motorPower(power, power, power, power, 0, 0, 0, 0);
}

struct motorPower driveBack(uint8_t power) {
  return motorPower(0, 0, 0, 0, power, power, power, power);
}

struct motorPower driveLeft(uint8_t power) {
  return motorPower(power, 0, 0, power, 0, power, power, 0);
}

struct motorPower driveRight(uint8_t power) {
  return motorPower(0, power, power, 0, power, 0, 0, power);
}

struct motorPower rotateWholeClockwise(uint8_t power) {
  return motorPower(0, power, 0, power, power, 0, power, 0);
}

struct motorPower rotateWholeCounterclockwise(uint8_t power) {
  return motorPower(power, 0, power, 0, 0, power, 0, power);
}

struct motorPower rotateBackClockwise(uint8_t power) {
  return motorPower(0, 0, 0, power, 0, 0, power, 0);
}

struct motorPower rotateBackCounterclockwise(uint8_t power) {
  return motorPower(0, 0, power, 0, 0, 0, 0, power);
}

struct motorPower rotateFrontClockwise(uint8_t power) {
  return motorPower(0, power, 0, 0, power, 0, 0, 0);
}

struct motorPower rotateFrontCounterclockwise(uint8_t power) {
  return motorPower(power, 0, 0, 0, 0, power, 0, 0);
}

struct motorPower moveFrontRightForward(uint8_t power) {
  return motorPower(power, 0, 0, 0, 0, 0, 0, 0);
}

struct motorPower moveFrontRightBackward(uint8_t power) {
  return motorPower(0, 0, 0, 0, power, 0, 0, 0);
}

struct motorPower moveFrontLeftForward(uint8_t power) {
  return motorPower(0, power, 0, 0, 0, 0, 0, 0);
}

struct motorPower moveFrontLeftBackward(uint8_t power) {
  return motorPower(0, 0, 0, 0, 0, power, 0, 0);
}

struct motorPower moveBackRightForward(uint8_t power) {
  return motorPower(0, 0, power, 0, 0, 0, 0, 0);
}

struct motorPower moveBackRightBackward(uint8_t power) {
  return motorPower(0, 0, 0, 0, 0, 0, power, 0);
}

struct motorPower moveBackLeftForward(uint8_t power) {
  return motorPower(0, 0, 0, power, 0, 0, 0, 0);
}

struct motorPower moveBackLeftBackward(uint8_t power) {
  return motorPower(0, 0, 0, 0, 0, 0, 0, power);
}