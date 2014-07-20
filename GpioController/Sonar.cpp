#include "USonic.h"

int main()
{
	USonic* u = new USonic("2", "25");
	u->sendSignal();
	delete u;
	return 0;
}
