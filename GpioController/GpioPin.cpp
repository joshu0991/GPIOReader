#include "GpioPin.h"

GpioPin::GpioPin(string pNum) : gpioPin(pNum)
{
	std::cout << pNum << " pin set " << std::endl;
}

GpioPin::~GpioPin()
{
	std::cout << "Deleting pin memory" <<std::endl;
}

void GpioPin::setPinMem(GpioPin* m)
{
	std::cout << "Pin memory is " << m << std::endl;
	pinMem = m;

}

int GpioPin::exportPin()
{
	int r_var = 0;
	std::string exportPath = "/sys/class/gpio/export";
	std::ofstream exportPin(exportPath.c_str());
	if(exportPin < 0)
	{
		std::cout << "Failed to open file" << std::endl;
		r_var = -1;
	}
	exportPin << this->gpioPin;
	exportPin.close();
	return r_var;
}

int GpioPin::unexportPin()
{
	int r_var = 0;
	std::string unexportPath = "/sys/class/gpio/unexport";
	std::ofstream unexportPin(unexportPath.c_str());
	if(unexportPin < 0)
	{
		std::cout << "Failed tonopen file " << std::endl;
		r_var = -1;
	}
	unexportPin << this->gpioPin;
	unexportPin.close(); 
	return r_var;
}
