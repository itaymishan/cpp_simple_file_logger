#include<stdio.h>
#include<iostream>
#include <fstream>
#include <string>

using namespace std;


class DebugLogger
{
public:
	
	// Methods
	bool CreateLogFile(char* path);
	bool CloseLogFile();
	bool WriteToLogger(char* str);
	bool WriteToLogger(string str);
	static DebugLogger *GetInstance();


	// attributes
	ofstream cpp_log_file;


private:

	// attributes
	DebugLogger* m_debugLogger;
	char *m_LogFilePathAndName;


	DebugLogger();



	


};
