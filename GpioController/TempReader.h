#ifndef TEMP_READER_H
#define TEMP_READER_H
#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctime>

using std::time_t;
using std::fstream;
using std::ifstream;
using std::string;
using std::cout;
using std::system;

class TempReader
{
	struct dirent *dirent;
	const char* bufOne;
	const char* bufTwo;
	float degC;
	float degF;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	pid_t procID;
	pid_t sid;

public:
	TempReader();
	TempReader(const char*, const char*);//will call the modprobe
	int readDS18B20();
	int writeTemp(float, float);
	float convertTemp(string);
	float getCel();
	float getFar();
	int setDaemon();
	int getTime();
};
#endif
