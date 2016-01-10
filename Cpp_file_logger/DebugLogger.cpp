#include <ctime>
#include "DebugLogger.h"


bool DebugLogger::CreateLogFile(char* path)
{
	bool bFuncRes = false;
	m_LogFilePathAndName = path;
	cpp_log_file.open(m_LogFilePathAndName,ios::app);
	if (cpp_log_file.is_open())
	{
		cpp_log_file.close();
		bFuncRes = true;
	}
	else
	{
		cout << "Unable to open file";
		bFuncRes = false;
	}
		return bFuncRes;
}


bool DebugLogger::CloseLogFile()
{
	cpp_log_file.close();
	return true;
}



bool DebugLogger::WriteToLogger(char *str)
{
	bool bFuncRes = false;
	cpp_log_file.open(m_LogFilePathAndName, ios::app);

	if (cpp_log_file.is_open())
	{
		time_t t = time(0);   // get time now
		struct tm * now = localtime( & t );
		// print time to log
		cpp_log_file	<< (now->tm_year + 1900) 
						<< '-' 
						<< (now->tm_mon + 1) 
						<< '-'
						<<  now->tm_mday
						<< " "
						<< now->tm_hour
						<< ":"
						<< now->tm_min
						<< ":"
						<< now->tm_sec
						<< "=> ";

		cpp_log_file << str << std::endl;
		cpp_log_file.close();
		bFuncRes = true;
	}
	else
	{
		cout << "Unable to open file";
		bFuncRes = false;
	}
	return bFuncRes;
}


bool DebugLogger::WriteToLogger(string str)
{
	bool bFuncRes = false;
	cpp_log_file.open(m_LogFilePathAndName, ios::app);
	if (cpp_log_file.is_open())
	{
		cpp_log_file << "-------------------------------------------------------------------------------------------------------------" << endl;
		time_t t = time(0);   // get time now
		struct tm * now = localtime( & t );
		// print time to log
		cpp_log_file	<< (now->tm_year + 1900) 
						<< '-' 
						<< (now->tm_mon + 1) 
						<< '-'
						<<  now->tm_mday
						<< " "
						<< now->tm_hour
						<< ":"
						<< now->tm_min
						<< ":"
						<< now->tm_sec
						<< "=> ";

		cpp_log_file << str << endl;
		cpp_log_file.close();
		bFuncRes = true;
	}
	else
	{
		cout << "Unable to open file";
		bFuncRes = false;
	}
	return bFuncRes;
}


DebugLogger* DebugLogger::GetInstance()
{
	static DebugLogger *m_sDebugLogger;
	if(NULL == m_sDebugLogger)
	{
		m_sDebugLogger = new DebugLogger();
	}
	return m_sDebugLogger;
}
