//#include "GpioPin.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
//using namespace GPIODriver;

void ouch(int sig)
{
printf("OUCH! - I got signal %d\n", sig);
exit(1);
}

int main()
{

struct sigaction act;
act.sa_handler = ouch;
sigemptyset(&act.sa_mask);
act.sa_flags = 0;
sigaction(SIGINT, &act, 0);
while(1) {
printf("Hello World!\n");
sleep(1);
}


//GpioPin* p23 = new GpioPin("23");
//GpioPin* p25 = new GpioPin("25");
//p25->exportPin();
//p23->exportPin();
//if(p25->getDirection() == "-1")
//{
//	p25->setDirection("out");
//}
//if(p23->getDirection() == "-1")
//{
//	p23->setDirection("in");
//}

//while(1)
//{
//sleep(3);
//std::cout<<"DOing work" <<std::endl;
//string instate = p23->getValue();
//if(instate == "0")
//{
//std::cout << "Button pressed" << std::endl;
//p25->setValue("1");
//sleep(3);
//p25->setDirection("in");
//string r = p25->getValue();
//std::cout << r << std::endl;
//sleep(3);
//p25->setValue("0");
//sleep(2);
//r = p25->getValue();
//std::cout << r << std::endl;
//p25->unexportPin();
//delete p23;
//delete p25;
//break;
//}
//}

return 0;
}
