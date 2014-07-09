#ifndef TEMP_READER_H
#define TEMP_READER_H
#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include <string.h>
#include  <fstream>

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

public:
	TempReader();
	TempReader(const char*, const char*);//will call the modprobe
	int readDS18B20();
	int writeTemp(float, float);
	float convertTemp(string);
	float getCel();
	float getFar();
};
#endif
