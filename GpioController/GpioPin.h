
#ifndef GPIO_PIN_H
#define GPIO_PIN_H 
#include <string>
#include <fstream>
#include <iostream>
using std::string;

class GpioPin
{
	GpioPin* pinMem;
	string gpioPin;
public:
	~GpioPin();
	GpioPin(string);
	int unexportPin();
	int exportPin();
	void setPinMem(GpioPin*);
};
#endif
