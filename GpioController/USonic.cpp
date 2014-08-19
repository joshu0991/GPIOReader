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
		sleep(2);
		tPin->setValue("1");
		usleep(1);
		tPin->setValue("0");
		while(rPin->getValue() == "0")
		{
			start = clock();
			std::cout << "start " << start << std::endl;
		}
		while(rPin->getValue() == "1")
		{
			stop = clock();
			std::cout << "Stop " << stop << std::endl;
		}
		std::cout << "Signal sent" << std::endl;
		time = (float)(stop - start);
		distance = time * 17150;
		std::cout << "Distance " << distance <<std::endl;
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
		std::cout << "R pin not 0" <<std::endl;
	//sendSignal(); 
	 while(rPin->getValue() == "0")
	    {
	     start = clock();
		std::cout << "ENtered first while" <<std::endl;
	    }
		std::cout << "Start " << start <<std::endl;
	  while(rPin->getValue() == "1")
	    {
	      stop = clock();
	    }
		std::cout << "Stop " << stop << std::endl;
	  time = (float) (stop - start);
		std::cout << "Time " << time <<  std::endl; 
	  distance = 17000 * time;
	std::cout << "Distance " << distance << std::endl;
	}
	return 0;
}
