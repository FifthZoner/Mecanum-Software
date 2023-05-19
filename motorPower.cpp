#include "motorPower.hpp"

motorPower::motorPower(void) {};

  // give motor power in the same order as in structure
motorPower::motorPower(uint8_t frf, uint8_t flf, uint8_t brf, uint8_t blf, uint8_t frb, uint8_t flb, uint8_t brb, uint8_t blb) {
    frontRightForward = frf;
    frontLeftForward = flf;
    backRightForward = brf;
    backLeftForward = blf;
    frontRightBackward = frb;
    frontLeftBackward = flb;
    backRightBackward = brb;
    backLeftBackward = blb;
}

motorPower motorPower::operator+(motorPower const& obj) {
    return motorPower(
      obj.frontRightForward + frontRightForward, obj.frontLeftForward + frontLeftForward,
      obj.backRightForward + backRightForward, obj.backLeftForward + backLeftForward,
      obj.frontRightBackward + frontRightBackward, obj.frontLeftBackward + frontLeftBackward,
      obj.backRightBackward + backRightBackward, obj.backLeftBackward + backLeftBackward);
}

void motorPower::operator+=(motorPower const& obj) {
      frontRightForward += obj.frontRightForward;
      frontLeftForward += obj.frontLeftForward,
      backRightForward += obj.backRightForward;
      backLeftForward += obj.backLeftForward;
      frontRightBackward += obj.frontRightBackward;
      frontLeftBackward += obj.frontLeftBackward;
      backRightBackward += obj.backRightBackward;
      backLeftBackward += obj.backLeftBackward;
  }

motorPower motorPower::operator-(motorPower const& obj) {
    return motorPower(
      -obj.frontRightForward + frontRightForward, -obj.frontLeftForward + frontLeftForward,
      -obj.backRightForward + backRightForward, -obj.backLeftForward + backLeftForward,
      -obj.frontRightBackward + frontRightBackward, -obj.frontLeftBackward + frontLeftBackward,
      -obj.backRightBackward + backRightBackward, -obj.backLeftBackward + backLeftBackward);
}

motorPower motorPower::operator*(float const& multiplier) {
    return motorPower(
      multiplier * frontRightForward, multiplier * frontLeftForward, multiplier * backRightForward, multiplier * backLeftForward,
      multiplier * frontRightBackward, multiplier * frontLeftBackward, multiplier * backRightBackward, multiplier * backLeftBackward);
}