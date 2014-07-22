#ifndef U_SONIC_H
#define U_SONIC_H
#include "GpioPin.h"
#include <ctime>
#include <string>
using namespace GPIODriver;
using std::string;
class USonic : public GpioPin
{
GpioPin* tPin;
GpioPin* rPin;
 std::clock_t start;
 std::clock_t stop;
float time;

public:
	~USonic();
	USonic();
	USonic(string, string);
	int sendSignal();
	int receiveSignal();
};
#endif
