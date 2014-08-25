#ifndef INPUT_DRIVER_H
#define INPUT_DRIVER_H

#include <iostream>
#include "GpioPin.h"
#include <string.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace GPIODriver;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::system;

class inputDriver : public GpioPin
{
	pid_t procId;
	pid_t sid;
	string request;
	char* inputFilePath;
	int readDataFile();
public:
	//int readDataFile();
	inputDriver(char*);
	int setDaemon();
	string getRequest();
};
#endif
