#include "TempReader.h"
int main()
{
TempReader reader("sudo modprobe w1-gpio", "sudo modprobe w1-therm");
reader.readDS18B20();
return 0;
}
