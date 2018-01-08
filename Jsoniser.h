/*
*
*FILE NAME	: Matcher.cpp
*FIRST VERSION  : 31/12/2017
*PROGRAMMER     : Nimal krishna
*DATE           : 31/12/2017
*		
*/

#ifndef JSONISER_H_
#define JSONISER_H_
#include <string>
using namespace std;

class Jsoniser {

private:

	string matchedList;
	int display;
	string displayMap;
public:

	string jsonSubstring;
	int  writeToOutputFile();
	string jsoniseData();
	Jsoniser();
	~Jsoniser();


		};

#endif /* JSONISER_H_ */
