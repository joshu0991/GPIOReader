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
	cout << request << endl;
	stream.close();
	return 0;
}

int inputDriver::setDaemon()
{
	procId = fork();
	if(procId < 0)
	{
		exit(EXIT_FAILURE);
	}
	if(procId > 0)
	{
		exit(EXIT_SUCCESS);
	}
	umask(0);
	sid = setsid();
	if(sid < 0)
	{
		exit(EXIT_FAILURE);
	}
	if(chdir("/") < 0)
	{
		exit(EXIT_FAILURE);
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	while(1)
	{
	readDataFile();
	}
	return 0;
}

string inputDriver::getRequest()
{
	return request;
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

