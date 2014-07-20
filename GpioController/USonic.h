#ifndef U_SONIC_H
#define U_SONIC_H
#include "GpioPin.h"
#include <string>
using namespace GPIODriver;
using std::string;
class USonic : public GpioPin
{
GpioPin* tPin;
GpioPin* rPin;

public:
	~USonic();
	USonic();
	USonic(string, string);
	int sendSignal();
	int receiveSignal();
};
#endif
