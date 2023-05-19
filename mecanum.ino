
#define FRONT_RIGHT_FORWARD 2
#define FRONT_LEFT_FORWARD 3
#define BACK_RIGHT_FORWARD 9
#define BACK_LEFT_FORWARD 8
#define FRONT_RIGHT_BACKWARD 6
#define FRONT_LEFT_BACKWARD 7
#define BACK_RIGHT_BACKWARD 5
#define BACK_LEFT_BACKWARD 4
#define CONTROLLER_DATA 10
#define CONTROLLER_ATTENTION 11
#define CONTROLLER_SEND 12
#define CONTROLLER_CLOCK 13

#include <stdint.h>
#include <math.h>
#include "PS2X_lib.h"

PS2X ps2x;

int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup() {

  Serial.begin(57600);

   error = ps2x.config_gamepad(CONTROLLER_CLOCK, CONTROLLER_SEND, CONTROLLER_ATTENTION, CONTROLLER_DATA, true, true);   //GamePad(clock, command, attention, data, Pressures?, Rumble?)

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

  if (error != 0){
    analogWrite(FRONT_RIGHT_FORWARD, 255);
    analogWrite(BACK_LEFT_FORWARD, 255);
  }
}



struct motorPower {

  uint8_t frontRightForward = 0;
  uint8_t frontLeftForward = 0;
  uint8_t backRightForward = 0;
  uint8_t backLeftForward = 0;
  uint8_t frontRightBackward = 0;
  uint8_t frontLeftBackward = 0;
  uint8_t backRightBackward = 0;
  uint8_t backLeftBackward = 0;

  motorPower() {}

  // give motor power in the same order as in structure
  motorPower(uint8_t frf, uint8_t flf, uint8_t brf, uint8_t blf, uint8_t frb, uint8_t flb, uint8_t brb, uint8_t blb) {
    frontRightForward = frf;
    frontLeftForward = flf;
    backRightForward = brf;
    backLeftForward = blf;
    frontRightBackward = frb;
    frontLeftBackward = flb;
    backRightBackward = brb;
    backLeftBackward = blb;
  }

  motorPower operator+(motorPower const& obj) {
    return motorPower(
      obj.frontRightForward + frontRightForward, obj.frontLeftForward + frontLeftForward,
      obj.backRightForward + backRightForward, obj.backLeftForward + backLeftForward,
      obj.frontRightBackward + frontRightBackward, obj.frontLeftBackward + frontLeftBackward,
      obj.backRightBackward + backRightBackward, obj.backLeftBackward + backLeftBackward);
  }

  void operator+=(motorPower const& obj) {
      frontRightForward += obj.frontRightForward;
      frontLeftForward += obj.frontLeftForward,
      backRightForward += obj.backRightForward;
      backLeftForward += obj.backLeftForward;
      frontRightBackward += obj.frontRightBackward;
      frontLeftBackward += obj.frontLeftBackward;
      backRightBackward += obj.backRightBackward;
      backLeftBackward += obj.backLeftBackward;
  }

  motorPower operator-(motorPower const& obj) {
    return motorPower(
      -obj.frontRightForward + frontRightForward, -obj.frontLeftForward + frontLeftForward,
      -obj.backRightForward + backRightForward, -obj.backLeftForward + backLeftForward,
      -obj.frontRightBackward + frontRightBackward, -obj.frontLeftBackward + frontLeftBackward,
      -obj.backRightBackward + backRightBackward, -obj.backLeftBackward + backLeftBackward);
  }

  motorPower operator*(float const& multiplier) {
    return motorPower(
      multiplier * frontRightForward, multiplier * frontLeftForward, multiplier * backRightForward, multiplier * backLeftForward,
      multiplier * frontRightBackward, multiplier * frontLeftBackward, multiplier * backRightBackward, multiplier * backLeftBackward);
  }
};

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

// za slabe silniki na niepelne moce
struct motorPower driveCustomDirection(int16_t direction) {
  direction = 360 - ((direction + 270) % 360);

  // deg to rad
  float angle = (float(direction) / 360.0) * 6.283;
  //float frontRightBackLeft = float(sin(angle - 0.7854) * 255.0);
  //float frontLeftBackRight = float(sin(angle + 0.7854) * 255.0);
  int frontLeftBackRight = (255 * (sin(angle) * 100 + cos(angle) * 100)) / 100 * 2;
  int frontRightBackLeft = (255 * (sin(angle) * 100 - cos(angle) * 100)) / 100 * 2;
  struct motorPower temp = motorPower(0, 0, 0, 0, 0, 0, 0, 0);
  if (frontRightBackLeft > 0.0) {
    temp.frontRightForward = frontRightBackLeft;
    temp.backLeftForward = frontRightBackLeft;
  } else {
    frontRightBackLeft *= -1;
    temp.frontRightBackward = frontRightBackLeft;
    temp.backLeftBackward = frontRightBackLeft;
  }

  if (frontLeftBackRight > 0.0) {
    temp.frontLeftForward = frontLeftBackRight;
    temp.backRightForward = frontLeftBackRight;
  } else {
    frontLeftBackRight *= -1;
    temp.frontLeftBackward = frontLeftBackRight;
    temp.backRightBackward = frontLeftBackRight;
  }


  return temp;
}

void loop() {
  /*
  setMotorPower(motorPower(255, 0, 0, 0, 0, 0, 0, 0));
  delay(500);
  setMotorPower(motorPower(0, 255, 0, 0, 0, 0, 0, 0));
  delay(500);
  setMotorPower(motorPower(0, 0, 255, 0, 0, 0, 0, 0));
  delay(500);
  setMotorPower(motorPower(0, 0, 0, 255, 0, 0, 0, 0));
  delay(500);
  setMotorPower(motorPower(0, 0, 0, 0, 255, 0, 0, 0));
  delay(500);
  setMotorPower(motorPower(0, 0, 0, 0, 0, 255, 0, 0));
  delay(500);
  setMotorPower(motorPower(0, 0, 0, 0, 0, 0, 255, 0));
  delay(500);
  setMotorPower(motorPower(0, 0, 0, 0, 0, 0, 0, 255));
  delay(500);
  */
  



 
    ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    motorPower final;
    if(ps2x.Button(PSB_L2) and !ps2x.Button(PSB_R2)){
      final+=(rotateWholeCounterclockwise(255));
    }
    else if(ps2x.Button(PSB_R2) and !ps2x.Button(PSB_L2)){
      final+=(rotateWholeClockwise(255));
    }
    else{
      final+=(motorPower());
    }
    if(ps2x.Button(PSB_PAD_UP)){
      if(ps2x.Button(PSB_PAD_RIGHT)){
        final+=(driveFrontRight(255));
      }
      else if (ps2x.Button(PSB_PAD_LEFT)){
        final+=(driveFrontLeft(255));
      }
      else{
        final+=(driveFront(255));
      }
    }
    else if(ps2x.Button(PSB_PAD_DOWN)){
      if(ps2x.Button(PSB_PAD_RIGHT)){
        final+=(driveBackRight(255));
      }
      else if (ps2x.Button(PSB_PAD_LEFT)){
        final+=(driveBackLeft(255));
      }
      else{
        final+=(driveBack(255));
      }
    }
    else if(ps2x.Button(PSB_PAD_RIGHT)){
      if(ps2x.Button(PSB_PAD_DOWN)){
        final+=(driveBackRight(255));
      }
      else if (ps2x.Button(PSB_PAD_UP)){
        final+=(driveFrontRight(255));
      }
      else{
        final+=(driveRight(255));
      }
    }
    else if(ps2x.Button(PSB_PAD_LEFT)){
      if(ps2x.Button(PSB_PAD_UP)){
        final+=(driveFrontLeft(255));
      }
      else if (ps2x.Button(PSB_PAD_DOWN)){
        final+=(driveBackLeft(255));
      }
      else{
        final+=(driveLeft(255));
      }
    }
    
    setMotorPower(final);







  delay(15);

    /*

    if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
         Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
         Serial.println("Select is being held");
         
         
     
    
      vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on 
                                              //how hard you press the blue (X) button    
    
    if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
    {   
        if(ps2x.Button(PSB_L3)){
          analogWrite(FRONT_RIGHT_FORWARD, 255);
    analogWrite(FRONT_LEFT_FORWARD, 255);
    analogWrite(BACK_RIGHT_FORWARD, 255);
    analogWrite(BACK_LEFT_FORWARD, 255);
     delay(500);
        }
         
        else if(ps2x.Button(PSB_R3)){
          analogWrite(FRONT_RIGHT_FORWARD, 255);
    analogWrite(FRONT_LEFT_FORWARD, 255);
    analogWrite(BACK_RIGHT_FORWARD, 255);
    analogWrite(BACK_LEFT_FORWARD, 255);
     delay(500);
        }
         
        else if(ps2x.Button(PSB_L2)){
           analogWrite(FRONT_RIGHT_FORWARD, 255);
    analogWrite(FRONT_LEFT_FORWARD, 255);
    analogWrite(BACK_RIGHT_FORWARD, 255);
    analogWrite(BACK_LEFT_FORWARD, 255);
     delay(500);
        }
        else if(ps2x.Button(PSB_R2)){
          analogWrite(FRONT_RIGHT_FORWARD, 255);
    analogWrite(FRONT_LEFT_FORWARD, 255);
    analogWrite(BACK_RIGHT_FORWARD, 255);
    analogWrite(BACK_LEFT_FORWARD, 255);
    delay(500);
        }
         
        else if(ps2x.Button(PSB_GREEN))
         Serial.println("Triangle pressed");
        else{
 
  setMotorPower(motorPower());
  
        } 
    }   
         
    
    if(ps2x.ButtonPressed(PSB_RED))             //will be TRUE if button was JUST pressed
         Serial.println("Circle just pressed");
         
    if(ps2x.ButtonReleased(PSB_PINK))             //will be TRUE if button was JUST released
         Serial.println("Square just released");     
    
    if(ps2x.NewButtonState(PSB_BLUE))            //will be TRUE if button was JUST pressed OR released
         Serial.println("X just changed");    
    
    
    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) // print stick values if either is TRUE
    {
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_LX), DEC); 
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_RY), DEC); 
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_RX), DEC); 
    } 
    */
}