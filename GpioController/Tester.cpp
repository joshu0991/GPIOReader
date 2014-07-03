#include "GpioPin.h"
using namespace GPIODriver;
int main()
{
GpioPin* p25 = new GpioPin("25");
p25->exportPin();
if(p25->getDirection() == "-1")
{
	p25->setDirection("out");
}
p25->setValue("1");
sleep(2);
p25->setValue("0");
p25->unexportPin();
delete p25;
return 0;
}
