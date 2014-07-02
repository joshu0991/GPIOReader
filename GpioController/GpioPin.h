
#ifndef GPIO_PIN_H
#define GPIO_PIN_H
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::ofstream;
class GpioPin
{
	string direction;
	string gpioPin;
public:
	~GpioPin();
	GpioPin(string);
	GpioPin(string, string);
	string getDirection();
	int setDirection(string direction);//set in or out
	int unexportPin();//unexport a pin
	int exportPin();//export a pin
	int setValue(string val);//for writing to pins
	int getValue();//pins current state
	int  getGpioNum();
};
#endif
