//daemon to constantly process input from the java server
#include "inputDriver.h"

inputDriver::inputDriver(const char* inputFilePath) : request(0)
{
	inputFile = inputFilePath;
}

int inputDriver::readDataFile()
{
	fstream stream("serverInput.txt");
	stream.open(inputFile);
	return 0;
}



int main()
{

	//when class is instantiated start a new prcess
	//instantiate in main program and get data from said var
	inputDriver driver("serverDriver.txt");
	//driver.readDataFile();

	return 0;
}
