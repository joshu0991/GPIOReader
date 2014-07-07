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
	int  r_var = 0;
	char path[] = "/sys/bus/w1/devices/";//path to temp sensor
	char folder[16];//specific id of temp sensor
	DIR *dir = opendir(path);
	if(dir != NULL)
	{
		dirent = readdir(dir);
		if(dirent->d_type == DT_LNK && strstr(dirent->d_name, "28-") != NULL)
		{
			strcpy(folder, dirent->d_name);
		}
		std::cout << dirent->d_name <<std::endl;
	}
	return r_var;
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
