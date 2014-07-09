#include "GpioPin.h"
using namespace GPIODriver;


GpioPin::GpioPin(string pNum) : gpioPin(pNum), direction("-1")
{
	std::cout << pNum << " pin " << pNum << " set" << std::endl;
}

GpioPin::GpioPin(string pNum, string dir) : gpioPin(pNum), direction(dir)
{
	std::cout << " Pin " << pNum << " set and direction is "  << dir << std::endl;
}

GpioPin::GpioPin(string pNum, string dir, string val) : gpioPin(pNum), direction(dir)
{
	exportPin();
	std::cout << "Pin " << pNum << " set and direction is " << dir << " Pin set as " << val <<std::endl;
	setValue(val);
}


GpioPin::~GpioPin()
{
	std::cout << "Deleting pin memory" <<std::endl;
}

int GpioPin::exportPin()
{
	string exportPath = "/sys/class/gpio/export";
	ofstream exportPin(exportPath.c_str());
	if(exportPin < 0)
	{
		std::cout << "Failed to open file" << std::endl;
		return -1;
	}
	exportPin << this->gpioPin;
	exportPin.close();
	return 0;
}

int GpioPin::unexportPin()
{
	string unexportPath = "/sys/class/gpio/unexport";
	ofstream unexportPin(unexportPath.c_str());
	if(unexportPin < 0)
	{
		std::cerr << "Failed to open file " << std::endl;
		return -1;
	}
	std::cout << "Pin unexported successfully " << std::endl;
	unexportPin << this->gpioPin;
	unexportPin.close();
	return 0;
}

//call if direction == -1
int GpioPin::setDirection(string direction)
{

	string valPath = "/sys/class/gpio/gpio" + this->gpioPin + "/direction";
	ofstream dFile(valPath.c_str());
	if(dFile < 0)
	{
		std::cerr << "Failed to open file " << std::endl;
		return -1;
	}
	dFile << direction;
	std::cout << "Direction set as '" << direction << "'" <<std::endl;
	dFile.close();
	return 0;
}

string GpioPin::getDirection()
{
	return this->direction;
}

int GpioPin::setValue(string value)
{
	string path = "/sys/class/gpio/gpio" + this->gpioPin + "/value";
	ofstream writer(path.c_str());
	if(writer < 0)
	{
		std::cout << "Failed to open pin " << std::endl;
		return -1;
	}
	if(value == "1")
	{
		std::cerr << "Pin is on " << std::endl;
	}
	else
	{
		std::cerr << "Pin is off " << std::endl;
	}
	writer << value;
	writer.close();
	return 0;
}

string GpioPin::getValue()
{
	string path = "/sys/class/gpio/gpio" + this->gpioPin + "/value";
	string value;
	//std::cout << path << std::endl;
	ifstream reader;
	reader.open(path.c_str());
	if(reader < 0)
	{
		std::cerr << "Failed to read file " << std::endl;
		return "-1";
	}
	reader >> value;
	//std::cout << value << std::endl;
	if (value != "0")
	{
		value = "1";
	}
	else
	{
		value = "0";
	}
	reader.close();
	return value;
}
//notes:
