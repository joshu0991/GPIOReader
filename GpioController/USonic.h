#ifndef U_SONIC_H
#define U_SONIC_H
#include "GpioPin.h"
#include <chrono>
#include <string>
using namespace GPIODriver;
using std::string;
class USonic : public GpioPin
{
GpioPin* tPin;
GpioPin* rPin;
auto start;
auto stop;
auto time;

public:
	~USonic();
	USonic();
	USonic(string, string);
	int sendSignal();
	int receiveSignal();
};
#endif
