#include "USonic.h"

USonic::USonic(){}

USonic::USonic(string iPin, string oPin)
{
	this->tPin = new super(iPin, "in");
}

int USonic::sendSingnal()
{
	int r = 0;
	return r;
}
