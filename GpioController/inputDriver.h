#ifndef INPUT_DRIVER_H
#define INPUT_DRIVER_H

#include <iostream>
#include "GpioPin.h"
#include <string.h>
#include <fstream>

using namespace GPIODriver;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;

class inputDriver : public GpioPin
{
	string request;
	char* inputFilePath;
	//int readDataFile(); 
public:
	int readDataFile();
	inputDriver(char*);
	int setDaemon();
	string getRequest();
};
#endif
