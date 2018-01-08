/*
*
*FILE NAME	: main.cpp
*FIRST VERSION  : 31/12/2017
*PROGRAMMER     : Nimal krishna
*DATE           : 31/12/2017
*DESCRIPTION    : This project is to search for a specific list item in the 'listings.txt' for a  match of any products in the 'products.txt'.In both files
	          informations are stored in JSON form.
		  The language used for the project is C++, in linux development environment.
		  Rapidjson is used to parse the json data in both files.
	          Search result is stored in the results.txt in JOSN form.Class Jsoniser is used for this purpose.
		  Search results are made more accurate by removing the case sensitivity and checking for the search word is contained in a longer string, and also 
		  based on the informations given in the product searched for (for some products family information is given, where as for some not. So whenever
		  family  information is given in the product to be searched for , a match of family is made a must condition for a sucessful match. In other cases 
	          family information is not used to find a match.)
*/


#include<string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include"Matcher.h"
#include"Jsoniser.h"


Matcher matchTheFiles;  //Object for the Matcher class


using namespace std;



int main(int argc, char* argv[]) 
 {
   

	matchTheFiles.checkForMatch();   //Compare the two lists and write the search results to 'output.txt'


   	return 0;
 }





