
#ifndef GPIO_PIN_H
#define GPIO_PIN_H 
#include <string>
#include <fstream>
#include <iostream>
using std::string;

class GpioPin
{
	string gpioPin;

public:
	GpioPin(string);
	int exportPin();
};
#endif
