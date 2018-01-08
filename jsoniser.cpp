/*
*
*FILE NAME	: Matcher.cpp
*FIRST VERSION  : 31/12/2017
*PROGRAMMER     : Nimal krishna
*DATE           : 31/12/2017
*DESCRIPTION    : This file imeplements the functions in Jsoniser class , which help to make JSON data based on the search performed by the matcher class.
*/

#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h> 
#include "Jsoniser.h"
#include "Matcher.h"


using namespace std;



Matcher matchobject;
int Matcher::NumberOfMatches;
bool Matcher::familyIspressent;
string Matcher::productFamily;
string Matcher::matchedList;
bool Matcher::familyInformationIsGiven ;
string Matcher::productModel;
string Matcher::productManafacturer;  
string Matcher::productName;

Jsoniser::Jsoniser()
 {
	//constructor
 }

Jsoniser::~Jsoniser()
 {
	//destructor
 }

/*
*
*Function name	: jsoniseData
*Parameters     : none
*Return         : string
*Description    : to make JSON subdata based on the search performed by the matcher class.
*/

string Jsoniser::jsoniseData()
 {
//Matcher matchedobject;

	//json substring without the array of list objects
	jsonSubstring=string("{\"product_name\":")+string("\"")+matchobject.productName+string("\"")+string(",")+string("\"listings\"")+string(":");

	return jsonSubstring;
 }




/*
*
*Function name	: writeToOutputFile
*Parameters     : none
*Return         : int
*Description    : The JSON data is written to 'output.txt'
*/

 int Jsoniser::writeToOutputFile()
 {
ofstream myfile;
myfile.open("output.txt",fstream::app);


	fstream output;
	output.open("output.txt",fstream::app);  // data is added to the existing data without deleting it.But Before the writing starts 
						 //the contents of 'output.txt' is cleared in matcher.cpp
	myfile<<Jsoniser::jsonSubstring;
	myfile<<"["<<matchobject.matchedList<<"]"<<"}"<<endl;  //Matched list has all the listings json data that matched with the product searched for.

        return 1;

 }
