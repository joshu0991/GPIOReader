CC = g++

all: TestDrive

TestDrive: GpioPin.o Tester.o
	$(CC) Tester.o GpioPin.o -o TestDrive

GpioPin.o: GpioPin.cpp
	$(CC) -Wall -c GpioPin.cpp

Tester.o: Tester.cpp
	$(CC) -Wall -c Tester.cpp

clean:
	rm -rf *o
