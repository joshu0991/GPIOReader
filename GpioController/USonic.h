#ifndef U_SONIC_H
#define U_SONIC_H
#include "GpioPin.h"
#include <string>
using namespace GPIODriver;
class USonic : public GpioPin
{
USonic* tPin;
USonic* rPin;
public:
	USonic();
	USonic(string, string);
	int sendSignal();
};
#endif
