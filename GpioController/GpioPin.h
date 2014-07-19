
#ifndef GPIO_PIN_H
#define GPIO_PIN_H
#include <string>
#include <fstream>
#include <iostream>


namespace GPIODriver
{
using std::ifstream;
using std::string;
using std::ofstream;
class GpioPin
{
	string gpioPin;
	string direction;
	int exported;
	int exportPin();
	int unexportPin();
public:
	~GpioPin();
	GpioPin();
	GpioPin(string);
	GpioPin(string, string);
  	GpioPin(string, string, string);
	string getDirection();
	int setDirection(string direction);//set in or out
	int setValue(string val);//for writing to pins
	string getValue();//pins current state
	int  getGpioNum();
	void setUp(string, string);
};
}
#endif
