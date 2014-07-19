CC = g++

all: TestDrive TempDriver SonarDriver

TestDrive: GpioPin.o Tester.o 
	$(CC) Tester.o GpioPin.o -o TestDrive

GpioPin.o: GpioPin.cpp
	$(CC) -Wall -c GpioPin.cpp

Tester.o: Tester.cpp
	$(CC) -Wall -c Tester.cpp

TempDriver: TempReader.o TempDriver.o
	$(CC) TempReader.o TempDriver.o -o TempDriver

TempReader.o: TempReader.cpp
	$(CC) -Wall -c TempReader.cpp

TempDriver.o: TempDriver.cpp
	$(CC) -Wall -c TempDriver.cpp

SonarDriver: Sonar.o USonic.o GpioPin.o
	$(CC) Sonar.o USonic.o GpioPin.o -o SonarDriver

Sonar.o: Sonar.cpp
	$(CC) -Wall -c Sonar.cpp

USonic.o: USonic.cpp
	$(CC) -Wall -c USonic.cpp 

clean: all
	rm f *o
