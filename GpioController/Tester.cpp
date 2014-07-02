#include "GpioPin.h"

int main()
{
GpioPin* p5 = new GpioPin("5");
p5->exportPin();
if(p5->getDirection() == "-1")
{
	p5->setDirection("in");
}
p5->unexportPin();
delete p5;
return 0;
}
