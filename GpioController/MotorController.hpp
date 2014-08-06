#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H 
#include "GpioPin.h"
using namespace GPIODriver;

class MotorController : public GpioPin
{
public:
  MotorController();
  MotorController(string, string);
  int moveForward();
  int moveBackward();
  int turnLeft();
  int turnRight();
};
#endif /* MOTOR_CONTROLLER_H  */
