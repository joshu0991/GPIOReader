//daemon to constantly process input from the java server
#include "inputDriver.h"

inputDriver::inputDriver(char* inputFilePath) : request("Hello")
{
	this->inputFilePath = inputFilePath;
}

//gets the speed and direction from the server speed and direction can be 1-4
int inputDriver::readDataFile()
{
	ifstream stream(inputFilePath);
	getline(stream, request);
	cout << request <<std::endl;
	stream.close();
	return 0;
}

int inputDriver::setDaemon()
{
	return 0;
}

string inputDriver::getRequest()
{
	string a = "stub";
	return a;
}

//test main
int main()
{

	//when class is instantiated start a new prcess
	//instantiate in main program and get data from said var
	inputDriver driver("serverInput.txt");
	driver.readDataFile();

	return 0;
}
