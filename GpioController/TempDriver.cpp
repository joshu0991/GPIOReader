#include "TempReader.h"
int main()
{
TempReader reader("sudo modprobe w1-gpio", "sudo modprobe w1-therm");
reader.setDaemon();
//reader.readDS18B20();
//reader.writeTemp(reader.getFar(), reader.getCel());
return 0;
}
