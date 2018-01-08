/*
*
*FILE NAME	: Matcher.cpp
*FIRST VERSION  : 31/12/2017
*PROGRAMMER     : Nimal krishna
*DATE           : 31/12/2017
*	
*/


#ifndef MATCHER_H_
#define MATCHER_H_
#include <string>
#include"Jsoniser.h"
using namespace std;

class Matcher {

friend class Jsoniser;

private:
	static int NumberOfMatches;
	static bool familyIspressent;
	static string productFamily;
	static string matchedList;
	static bool familyInformationIsGiven ;
	static string productModel;
	static string productManafacturer;
	static string productName;
	string displayMap;
	int display;
	int TotalNumberOfItemsInProductlistChecked;
	int TotalNumberOfMatchesFound;
	char listingsFileLine[800];
	char productsFileLine[800];
	string listManafacturer;
	string listTitle;
	bool manafacturerIspressent;
	bool modelIspressent;
	static string jsonSubstring;
	string productFamilyCapital;
 	string productModelCapital; string productManafacturerCapital;
	string listManafacturerCapital;
	string listTitleCapital;
	int foundMatch;
	int foundMatch1;
	string productsFileLineString;
public:
	bool containsOnlyExactword(const std::string& sentence, const std::string& word);
	void checkForMatch(); 
	Matcher();
	~Matcher();

	};

#endif /* MATCHER_H_ */
