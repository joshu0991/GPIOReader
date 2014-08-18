#include "USonic.h"

int main()
{
	//USOnic(in, out)
	//in voltage must be pulled down to 3.3 voltes
	//vout = vin * R2/(R1+R2) to calculate needed ressistance
	USonic* u = new USonic("24", "23");
	u->sendSignal();
	u->receiveSignal();
	delete u;
	return 0;
}
