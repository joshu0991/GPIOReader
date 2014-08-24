#ifndef INPUT_DRIVER_H
#define INPUT_DRIVER_H

#include <iostream>
#include "GpioPin.h"
#include <string.h>
#include <fstream>

using namespace GPIODriver;
using std::fstream;
using std::cout;

class inputDriver : public GpioPin{

	const char* request;
	int readDataFile(); 
	const char* inputFile;
public:
	inputDriver(const char*);
	int setDaemon();
	const char* getRequest();
};
#endif /* INPUT_DRIVER_H  */
