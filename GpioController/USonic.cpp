#include "USonic.h"

USonic::USonic(string iPin,  string oPin)
{
	tPin = new GpioPin(oPin, "out");
	rPin = new GpioPin(iPin, "in");
}

USonic::~USonic()
{
	std::cout <<"Cleaning up ultrasonic"<<std::endl;
	delete tPin;
	delete rPin;
}

int USonic::sendSignal()
{
	int r = 0;
	std::cout <<"hello" <<std::endl;
	//std::cout << this->tPin << std::endl;
	//std::cout << this->rPin << std::endl;
	return r;
}

