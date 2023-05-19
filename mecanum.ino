//=============================================================================//
// Oprogramowanie do sterowania robotem z kołami omnikierunkowymi typu mecanum //
// Autor: Szymon Jabłoński                                                     //
//=============================================================================//

#include "motorPower.hpp"
#include "controls.hpp"

controllerData controller;

void setup(void) {

  Serial.begin(57600);

  controller.error = controller.ps2x.config_gamepad(CONTROLLER_CLOCK, CONTROLLER_SEND, CONTROLLER_ATTENTION, CONTROLLER_DATA, true, true);

  pinMode(FRONT_RIGHT_FORWARD, OUTPUT);
  pinMode(FRONT_LEFT_FORWARD, OUTPUT);
  pinMode(BACK_RIGHT_FORWARD, OUTPUT);
  pinMode(BACK_LEFT_FORWARD, OUTPUT);
  pinMode(FRONT_RIGHT_BACKWARD, OUTPUT);
  pinMode(FRONT_LEFT_BACKWARD, OUTPUT);
  pinMode(BACK_RIGHT_BACKWARD, OUTPUT);
  pinMode(BACK_LEFT_BACKWARD, OUTPUT);


  analogWrite(FRONT_RIGHT_FORWARD, 0);
  analogWrite(FRONT_LEFT_FORWARD, 0);
  analogWrite(BACK_RIGHT_FORWARD, 0);
  analogWrite(BACK_LEFT_FORWARD, 0);
  analogWrite(FRONT_RIGHT_BACKWARD, 0);
  analogWrite(FRONT_LEFT_BACKWARD, 0);
  analogWrite(BACK_RIGHT_BACKWARD, 0);
  analogWrite(BACK_LEFT_BACKWARD, 0);

  if (controller.error != 0){
    analogWrite(FRONT_RIGHT_FORWARD, 255);
    analogWrite(BACK_LEFT_FORWARD, 255);
  }
}

// main function that sets given power levels to given motor directions, add all the needed movement types and pass them to it
void setMotorPower(struct motorPower values) {
  analogWrite(FRONT_RIGHT_FORWARD, values.frontRightForward);
  analogWrite(FRONT_LEFT_FORWARD, values.frontLeftForward);
  analogWrite(BACK_RIGHT_FORWARD, values.backRightForward);
  analogWrite(BACK_LEFT_FORWARD, values.backLeftForward);
  analogWrite(FRONT_RIGHT_BACKWARD, values.frontRightBackward);
  analogWrite(FRONT_LEFT_BACKWARD, values.frontLeftBackward);
  analogWrite(BACK_RIGHT_BACKWARD, values.backRightBackward);
  analogWrite(BACK_LEFT_BACKWARD, values.backLeftBackward);
}

// to use in other files
void delayBypass(uint16_t time){
  delay(time);
}

void loop(void) {
    
  readController(controller);

  // can be increased or decreased if movement is not of the desired fluidity
  delay(15);

}