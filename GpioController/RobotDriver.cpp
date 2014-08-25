//start processes
//start server
#include "TempReader.h"


int main()
{
	string command;
	TempReader reader("sudo modprobe w1-gpio", "sudo modprobe w1-therm");
	inputDriver driver("serverInput.txt");
	reader.setDaemon();
	driver.setDaemon();
	command = driver.getRequest();
	return 0;
}
