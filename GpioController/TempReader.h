#ifndef TEMP_READER_H
#define TEMP_READER_H
#include <cstdlib>
#include <iostream>
#include "GpioPin.h"
#include <dirent.h>
#include <string.h>
//using std::string;
using std::cout;
using std::system;
using namespace GPIODriver;
class TempReader
{
	struct dirent *dirent;
	const char* bufOne;
	const char* bufTwo;
public:
	TempReader();
	TempReader(const char*, const char*);//will call the modprobe
	int readDS18B20();
	float convertTemp(string);
};


#endif
