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
time_t start;
time_t stop;
float pulseTime;
float distance;
public:
	~USonic();
	USonic();
	USonic(string, string);
	int sendSignal();
	int receiveSignal();
	float getDistance();
};
#endif /* U_SONIC_H  */
