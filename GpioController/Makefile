CC = g++

all: TestDrive TempDriver

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

clean:
	rm -rf *o
