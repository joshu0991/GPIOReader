#include "TempReader.h"


TempReader::TempReader()
{
	cout << "Warning: proper kernal moduals may not be installed." << std::endl;
}


TempReader::TempReader(const char* b, const char* c) : bufOne(b), bufTwo(c)
{
	//call commands
	system(bufOne);
	system(bufTwo);
	cout << "Added kernal mods" << std::endl;
}


int TempReader::readDS18B20()
{
	float celcius;
	float farenheit;
	int  r_var = 0;
	char path[] = "/sys/bus/w1/devices";//path to temp sensor
	char sensor[16];//specific id of sensor
	char devPath[128];
	DIR *dir = opendir(path);
	string data;
	if(dir != NULL)
	{
		while((dirent = readdir(dir)))
		{
			if(dirent->d_name[0] == '.' || dirent->d_name[0] == 'w')
			{
				continue;
			}
			else
			{
				strcpy(sensor, dirent->d_name);
				(void) closedir(dir);
				sprintf(devPath, "%s/%s/w1_slave", path, sensor);
				break;
			}
		}
		ifstream tempStream(devPath);
		getline(tempStream, data);
		getline(tempStream, data);
		tempStream.close();
		celcius = convertTemp(data);
		farenheit = (((celcius * 9)/5)+32);
		degC = celcius;
		degF = farenheit;
		printf("Farenheit %.2f\n", farenheit);
		printf("Celcius %.2f\n", celcius);

	}

	return r_var;
}


float TempReader::convertTemp(string d)
{
	unsigned int counter = 0;
	unsigned int tPos = 0;
	char buf[5];//holds temperature
	while(counter < d.length())
	{	//loopthough until a t is found
		if(d[counter] == 't')
		{	//save the index where t is found in tPos var and break
			tPos = counter;
			break;
		}
		counter++;
	}
	tPos+=2;//tPos add two to get to first didget of temp
	counter = 0;
	while(tPos < d.length())
	{	//populate temporary buffer
		buf[counter] = d[tPos];
		tPos++;
		counter++;
	}
	//convert to celcius
	float temp = atof(buf);
	float celcius = temp/1000;
	return celcius;
}
//writer for outside of class
int TempReader::writeTemp(float farenheit, float celcius)
{
	fstream writer;
	writer.open("Temps.txt", fstream::out);
	if(writer < 0)
	{
		std::cout << "Failed to open file" <<std::endl;
		return -1;
	}
	writer << farenheit << " F, " << celcius << " C " << year << " " << month << " " << day << " " << hour << " " << min << " " << sec << std::endl;
	writer.close();
	return 0;
}

//For use with daemon not for use outside of class
int TempReader::writeTemp()
{
	fstream writer;
	fstream logs;
	writer.open("Temps.txt", fstream::out);
	logs.open("logs.txt", fstream::out);
	if(writer < 0 || logs < 0)
	{
		logs << "Failed to open file" << std::endl;
		logs.close();
		return -1;
	}
	writer << degF << " F, " << degC << " C " << year << " " << month << " " << day << " " << hour << " " << min << " " << sec << std::endl;
	writer.close();
	return 0;
}


float TempReader::getCel()
{
	return degC;
}

float TempReader::getFar()
{
	return degF;
}

int TempReader::setDaemon()
{
	//make a new process ID
	procID = fork();
	if(procID < 0)
	{
		exit(EXIT_FAILURE);
	}
	//show process id
	if(procID > 0)
	{
		exit(EXIT_SUCCESS);
	}
	umask(0);
	sid = setsid();
	if(sid < 0)
	{
		exit(EXIT_FAILURE);
	}
	if(chdir("/") < 0)
	{
		exit(EXIT_FAILURE);
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	while(1)
	{
	readDS18B20();
	getTime();
	writeTemp();
	sleep(600);//update every ten minutes
	}
	return 0;
}

int TempReader::getTime()
{
	time_t t = time(0);
	struct tm* now = localtime(&t);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	day = now->tm_mday;
	hour = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
	return 0;
}
/*
 * On Linux, the dirent structure is defined as follows:
 *
 *struct dirent {
 *   ino_t d_ino;             inode number
 *   off_t d_off;             offset to the next dirent
 *   unsigned short d_reclen; length of this record
 *   unsigned char  d_type;   type of file; not supported
 *		              by all file system types
 *   char d_name[256];        filename
 *};
 */
