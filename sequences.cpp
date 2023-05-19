#include "sequences.hpp"
#include "motorPower.hpp"
#include "movement.hpp"

// some sequences for show

void delay();

void triangleSequence(void){
    setMotorPower(rotateWholeClockwise(255));
    delayBypass(1000);
    setMotorPower(driveFront(255));
    delayBypass(2000);
    setMotorPower(rotateWholeCounterclockwise(255));
    delayBypass(2000);
    setMotorPower(driveBack(255));
    delayBypass(2000);
    setMotorPower(rotateWholeClockwise(255));
    delayBypass(2000);
    setMotorPower(driveBack(255));
    delayBypass(2000);
    setMotorPower(rotateWholeCounterclockwise(255));
    delayBypass(2000);
    setMotorPower(driveFront(255));
    delayBypass(2000);
    setMotorPower(rotateWholeClockwise(255));
    delayBypass(1000);
}

void squareSequence(void){
    setMotorPower(driveFront(255));
    delayBypass(2000);
    setMotorPower(driveRight(255));
    delayBypass(2000);
    setMotorPower(driveBack(255));
    delayBypass(2000);
    setMotorPower(driveLeft(255));
    delayBypass(2000);
}
 
void circleSequence(void){
    setMotorPower(driveFront(255));
    delayBypass(1000);
    setMotorPower(driveFrontRight(255));
    delayBypass(1000);
    setMotorPower(driveRight(255));
    delayBypass(1000);
    setMotorPower(driveBackRight(255));
    delayBypass(1000);
    setMotorPower(driveBack(255));
    delayBypass(1000);
    setMotorPower(driveBackLeft(255));
    delayBypass(1000);
    setMotorPower(driveLeft(255));
    delayBypass(1000);
    setMotorPower(driveFrontLeft(255));
    delayBypass(1000);
}
    
void crossSequence(void){
    setMotorPower(driveFrontRight(255));
    delayBypass(1000);
    setMotorPower(driveBackLeft(255));
    delayBypass(2000);
    setMotorPower(driveFrontRight(255));
    delayBypass(1000);
    setMotorPower(driveBackRight(255));
    delayBypass(1000);
    setMotorPower(driveFrontLeft(255));
    delayBypass(2000);
    setMotorPower(driveBackRight(255));
    delayBypass(1000);
}