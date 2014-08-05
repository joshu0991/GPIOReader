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
		rPin = 0;
	}
}

int USonic::sendSignal()
{
	if(tPin > 0)
	{
		tPin->setValue("1");
		usleep(1);
		tPin->setValue("0");
	}
	else
	{
		return -1;
	}
	return 0;
}

//returns distance in centimeters
int USonic::receiveSignal()
{

	if(rPin > 0)
	{
	  while(rPin->getValue() == "0")
	    {
	     start = clock();
	    }
	  while(rPin->getValue() == "1")
	    {
	      stop = clock();
	    }
	  time = (float) (stop - start);
	  distance = 17000 * time;
	}
	return 0;
}
