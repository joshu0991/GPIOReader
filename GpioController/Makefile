CC = g++ -std=c++0x

all: TestDrive TempDriver SonarDriver inputDriver #RobotDriver

TestDrive: GpioPin.o Tester.o 
	$(CC) Tester.o GpioPin.o -o TestDrive

GpioPin.o: GpioPin.cpp GpioPin.h
	$(CC) -Wall -c GpioPin.cpp

Tester.o: Tester.cpp
	$(CC) -Wall -c Tester.cpp

TempDriver: TempReader.o TempDriver.o
	$(CC) TempReader.o TempDriver.o -o TempDriver

TempReader.o: TempReader.cpp TempReader.h
	$(CC) -Wall -c TempReader.cpp

TempDriver.o: TempDriver.cpp
	$(CC) -Wall -c TempDriver.cpp

SonarDriver: Sonar.o USonic.o GpioPin.o
	$(CC) Sonar.o USonic.o GpioPin.o -o SonarDriver

Sonar.o: Sonar.cpp
	$(CC) -Wall -c Sonar.cpp

USonic.o: USonic.cpp USonic.h
	$(CC) -Wall -c USonic.cpp 

inputDriver.o: inputDriver.h inputDriver.cpp GpioPin.cpp GpioPin.h
	$(CC) -Wall -c inputDriver.cpp

inputDriver: GpioPin.o inputDriver.o
	$(CC) GpioPin.o inputDriver.o -o inputDriver

#RobotDriver.o: inputDriver.o TempReader.o Sonar.o GpioPin.o
#	$(CC) inputDriver.o TempReader.o Sonar.o GpioPin.o -o RobotDriver

clean:
	rm -rf all GpioPin.o Tester.o TempReader.o TempDriver.o Sonar.o USonic.o
