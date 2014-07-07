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
