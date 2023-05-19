#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include "PS2X_lib.h"

struct controllerData{
    PS2X ps2x;
    int error = 0; 
    byte type = 0;
    byte vibrate = 0;
};

void readController(controllerData& controller);

// pins used for controller io
// only change if pin layout changes
#define CONTROLLER_DATA 10
#define CONTROLLER_ATTENTION 11
#define CONTROLLER_SEND 12
#define CONTROLLER_CLOCK 13

#endif