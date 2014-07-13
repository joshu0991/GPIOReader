#include "USonic.h"

int main()
{
	USonic* u = new USonic("4", "5");
	u->sendSignal();
	return 0;
}
