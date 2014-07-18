#include "SignalCatcher.h"

SignalCatcher::SignalCatcher()
{
	sigAc.sa_handler ccHandler;
	sigemptyset(&sigAc.sa_mask);
	sigAc.sa_flags = 0;
	sigaction(SIGINT,&sigAc,NULL);
}

void SignalCatcher::ccHandler(int sig)
{
	std::cout << "signal caught "<<std::endl;
}
