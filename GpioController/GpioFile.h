#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <fcntl.h>
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
class GpioFile
{
	int fileHandle;

public:
	GpioFile(char* filePath, int flags = O_RDWR)
	{
	//cout <<  "Opening" << filePath << endl;
	fileHandle = open(filePath, flags);
	cout << "File opened successfully" <<endl;
	}
	
};
