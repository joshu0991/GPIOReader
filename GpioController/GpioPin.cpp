#include "GpioPin.h"

GpioPin::GpioPin(string pNum) : gpioPin(pNum)
{
	std::cout << pNum << " pin set " << std::endl;
}

int GpioPin::exportPin()
{
	int r_var = 0;
	std::string exportPath = "/sys/class/gpio/export";
	std::ofstream exportPin(exportPath.c_str());
	if(exportPin < 0)
	{
		r_var = -1;
	}
	std::cout << r_var << std::endl;
	//exportPin << this->gpioPin;
	return r_var;

}
