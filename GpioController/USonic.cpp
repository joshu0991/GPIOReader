#include "USonic.h"

USonic::USonic(){}

USonic::USonic(string iPin,  string oPin)
{
	tPin = new GpioPin(oPin, "out");
	rPin = new GpioPin(iPin, "in");
}

USonic::~USonic()
{
	if(tPin !=0 || rPin!=0)
	{
		std::cout <<"Cleaning up ultrasonic"<<std::endl;
		delete tPin;
		delete rPin;
		tPin = 0;
		rPin =0;
	}
}

int USonic::sendSignal()
{
	int r = 0;
	std::cout << this->tPin << std::endl;
	std::cout << this->rPin << std::endl;
	return r;
}
