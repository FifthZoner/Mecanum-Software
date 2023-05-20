#include "controls.hpp"
#include "motorPower.hpp"
#include "movement.hpp"
#include "sequences.hpp"

// use this to determine how much to pull the joystick to register, be reasonable
#define joystickThreshold 30
// do not change these!
#define limitUpper 128 + joystickThreshold
#define limitLower 128 - joystickThreshold

motorPower final;

// moving in 8 directions
void readArrows(controllerData& controller){
    if(controller.ps2x.Button(PSB_PAD_UP)){
      if(controller.ps2x.Button(PSB_PAD_RIGHT)){
        final+=(driveFrontRight(255));
      }
      else if (controller.ps2x.Button(PSB_PAD_LEFT)){
        final+=(driveFrontLeft(255));
      }
      else{
        final+=(driveFront(255));
      }
    }
    else if(controller.ps2x.Button(PSB_PAD_DOWN)){
      if(controller.ps2x.Button(PSB_PAD_RIGHT)){
        final+=(driveBackRight(255));
      }
      else if (controller.ps2x.Button(PSB_PAD_LEFT)){
        final+=(driveBackLeft(255));
      }
      else{
        final+=(driveBack(255));
      }
    }
    else if(controller.ps2x.Button(PSB_PAD_RIGHT)){
      if(controller.ps2x.Button(PSB_PAD_DOWN)){
        final+=(driveBackRight(255));
      }
      else if (controller.ps2x.Button(PSB_PAD_UP)){
        final+=(driveFrontRight(255));
      }
      else{
        final+=(driveRight(255));
      }
    }
    else if(controller.ps2x.Button(PSB_PAD_LEFT)){
      if(controller.ps2x.Button(PSB_PAD_UP)){
        final+=(driveFrontLeft(255));
      }
      else if (controller.ps2x.Button(PSB_PAD_DOWN)){
        final+=(driveBackLeft(255));
      }
      else{
        final+=(driveLeft(255));
      }
    }
}

// rotating with front and back
void readBack(controllerData& controller){
    if(controller.ps2x.Button(PSB_L1)){
      final+=(rotateFrontCounterclockwise(255));
    }
    if(controller.ps2x.Button(PSB_R1)){
      final+=(rotateFrontClockwise(255));
    }
    if(controller.ps2x.Button(PSB_L2)){
      final+=(rotateBackCounterclockwise(255));
    }
    if(controller.ps2x.Button(PSB_R2)){
      final+=(rotateBackClockwise(255));
    }
}

// direction values unknown TODO will try with up right
// moving
void readLeftAnalog(controllerData& controller){
    if (controller.ps2x.Analog(PSS_LX) > limitUpper){
        if (controller.ps2x.Analog(PSS_LY) < limitLower){
            final+=(driveFrontRight(255));
        }
        else if (controller.ps2x.Analog(PSS_LY) > limitUpper){
            final+=(driveBackRight(255));
        }
        else{
            final+=(driveRight(255));
        }
    }
    else if (controller.ps2x.Analog(PSS_LX) < limitLower){
        if (controller.ps2x.Analog(PSS_LY) < limitLower){
            final+=(driveFrontLeft(255));
        }
        else if (controller.ps2x.Analog(PSS_LY) > limitUpper){
            final+=(driveBackLeft(255));
        }
        else{
            final+=(driveLeft(255));
        }
    }
    else {
        if (controller.ps2x.Analog(PSS_LY) < limitLower){
            final+=(driveFront(255));
        }
        else if (controller.ps2x.Analog(PSS_LY) > limitUpper){
            final+=(driveBack(255));
        }
    }
}

// direction values unknown TODO will try with up right
// rotating
void readRightAnalog(controllerData& controller){
    if (controller.ps2x.Analog(PSS_RX) > limitUpper){
        final+=(rotateWholeClockwise(255));
    }
    else if (controller.ps2x.Analog(PSS_RX) < limitLower){
        final+=(rotateWholeCounterclockwise(255));
    }
}

void readSequences(controllerData& controller){
    if(controller.ps2x.Button(PSB_GREEN)){
        triangleSequence();
        controller.ps2x.read_gamepad(false, controller.vibrate);
    }
    if(controller.ps2x.Button(PSB_PINK)){
        squareSequence();
        controller.ps2x.read_gamepad(false, controller.vibrate);
    }
    if(controller.ps2x.Button(PSB_RED)){
        circleSequence();
        controller.ps2x.read_gamepad(false, controller.vibrate);
    }
    if(controller.ps2x.Button(PSB_BLUE)){
        crossSequence();
        controller.ps2x.read_gamepad(false, controller.vibrate);
    }
}

void readController(controllerData& controller){

    final = motorPower();
    controller.ps2x.read_gamepad(false, controller.vibrate);

    readArrows(controller);

    readBack(controller);

    readLeftAnalog(controller);

    readRightAnalog(controller);

    setMotorPower(final);

    readSequences(controller);
}