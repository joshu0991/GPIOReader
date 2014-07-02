#include "GpioPin.h"

int main()
{
GpioPin* p5 = new GpioPin("5");
p5->setPinMem(p5);
p5->exportPin();
delete p5;
return 0;
}
