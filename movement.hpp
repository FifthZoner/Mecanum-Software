#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <stdint.h>

struct motorPower driveFrontLeft(uint8_t power);

struct motorPower driveFrontRight(uint8_t power);

struct motorPower driveBackRight(uint8_t power);

struct motorPower driveBackLeft(uint8_t power);

struct motorPower driveFront(uint8_t power);

struct motorPower driveBack(uint8_t power);

struct motorPower driveLeft(uint8_t power);

struct motorPower driveRight(uint8_t power);

struct motorPower rotateWholeClockwise(uint8_t power);

struct motorPower rotateWholeCounterclockwise(uint8_t power);

struct motorPower rotateBackClockwise(uint8_t power);

struct motorPower rotateBackCounterclockwise(uint8_t power);

struct motorPower rotateFrontClockwise(uint8_t power);

struct motorPower rotateFrontCounterclockwise(uint8_t power);

struct motorPower moveFrontRightForward(uint8_t power);

struct motorPower moveFrontRightBackward(uint8_t power);

struct motorPower moveFrontLeftForward(uint8_t power);

struct motorPower moveFrontLeftBackward(uint8_t power);

struct motorPower moveBackRightForward(uint8_t power);

struct motorPower moveBackRightBackward(uint8_t power);

struct motorPower moveBackLeftForward(uint8_t power);

struct motorPower moveBackLeftBackward(uint8_t power);

#endif