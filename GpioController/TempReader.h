#ifndef TEMP_READER_H
#define TEMP_READER_H

#include "GpioPin.h"
using namespace GPIODriver;
class TempReader
{
private:
	//string command1 = "sudo modprobe w1-gpio";
	//string command2 = "sudo modprobe w1-therm";
public:
	TempReader();//will call the modprobe
	auto readDS18B20();

};

#endif
