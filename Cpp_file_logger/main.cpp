#include <string>
#include <sstream>
#include "DebugLogger.h"


int main()
{
	////////////////////////////////////////////////    Singleton Init   ////////////////////////////////////////////////
	// Init Logger once
	std::stringstream stringBuilder;
	DebugLogger *debugLog = DebugLogger::GetInstance();
	debugLog->CreateLogFile("..\\..\\itay_log_file.txt");
	
	// examples for variables
	string ddd		= "ddd";
	int aaa			= 21;
	double bbb		= 0.3333;
	float ccc		= 12334;

	// Format the string 'param: value'
	stringBuilder	<< "\nparam1:"	<< ddd
					<< "\nparam2:"	<< aaa
					<< "\nparam3:"	<< bbb
					<< "\nparam4:"	<< ccc;
	
	debugLog->WriteToLogger(stringBuilder.str());
	// clear string
	stringBuilder.str("");

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




}
