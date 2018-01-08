/*
*
*FILE NAME	: Matcher.cpp
*FIRST VERSION  : 31/12/2017
*PROGRAMMER     : Nimal krishna
*DATE           : 31/12/2017
*DESCRIPTION    : This file imeplements the functions in matcher class , which help to match the items in listings,txt file to that 
                  in products.txt file 			
*/



#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h> 
#include "Matcher.h"
#include <algorithm>
#include <cctype>
#include<regex>


using namespace rapidjson;
using namespace std;

Matcher::Matcher()
 {
	//constructor
 }

Matcher::~Matcher()
 {
	//destructor
 }

/*
*
*Function name	: checkForMatch
*Parameters     : none
*Return         : void
*Description    : Checks if the product list data matches  the entries in listings list
*/

void Matcher::checkForMatch() {

   
	Jsoniser jsoniserObject;
	std::ofstream clearTheFile; 
	clearTheFile.open("output.txt", std::ofstream::out | std::ofstream::trunc);  // Used to initialise 'output.txt' as  an empty file.
	clearTheFile.close();
	NumberOfMatches=0;    // Initialised the total number of matches found based on the search.
	std::ifstream productsFile;
	std::ifstream listingsFile;
	// checks the file products.txt exists or not
	try{
	productsFile.open("products.txt", std::ios::in);
		if( !(productsFile.is_open())    )
		{
		throw "Cant open the file \"producs.txt\" exiting scanning";
		}
   
   	   }
		catch(const char* msg)
	  	 {
		cout << "\033[31m" <<msg <<  "\033[0m" <<endl;
 
          	 }  
// checks the file listings.txt exists or not
	try{
	listingsFile.open("listings.txt", std::ios::in);
		if( !(listingsFile.is_open())    )
		{
		throw "Cant open the file \"listings.txt\" exiting scanning";
		}
   
  	   }
		catch(const char* msg)
	  	 {
		cout << "\033[31m" <<msg <<  "\033[0m" <<endl;
          	 }
 
	
	while(productsFile.peek() != EOF) 	      // The product file has not reached its end 
	{
	productsFile.getline(productsFileLine, 800);  // Get the next line in product file
	TotalNumberOfItemsInProductlistChecked+=1;
		if(NumberOfMatches > 0)
		{
 		jsoniserObject.writeToOutputFile() ; 	      // The search results are written to output,txt everytime a complete lookup is done in the listings 

		}			       	      	      // file for  a specific product item searched for

	matchedList="";     // Reinitialise matched list after a complete lookup is done in the listings file for a specific product item searched for
	NumberOfMatches=0;  // Reinitialise number of matches after a complete lookup is done in the listings file for a specific product item searched for


		if(listingsFile.peek() == EOF)    		  // All the items in the listings file have been compared with a specific item in the product list
								  // we are looking for
		{
		listingsFile.close();
		listingsFile.open("listings.txt", std::ios::in); // Next item to be read from the listings file is again set back to the first item in the listings
								 // list

		}
	while(listingsFile.peek() != EOF)  		  // The listings  file has not reached its end 
	{


	listingsFile.getline(listingsFileLine, 800);	  // Get the next line 
	Document productsDocument,listingsDocument;
	productsDocument.Parse(productsFileLine);		
	listingsDocument.Parse(listingsFileLine);
	//Product and  listings  informations are extracted	
	productName =productsDocument["product_name"].GetString();
	productManafacturer =productsDocument["manufacturer"].GetString();
	productManafacturerCapital=productManafacturer;
	//Information is capitalised to remove case sensitivity of the search
	transform(productManafacturerCapital.begin(), productManafacturerCapital.end(), productManafacturerCapital.begin(),(int (*)(int))toupper);
	listManafacturer =listingsDocument["manufacturer"].GetString();
	listManafacturerCapital=listManafacturer;
	//Information is capitalised to remove case sensitivity of the search
	transform(listManafacturerCapital.begin(), listManafacturerCapital.end(), listManafacturerCapital.begin(),(int (*)(int))toupper);
	productModel =productsDocument["model"].GetString();
	productModelCapital=productModel;
	//Information is capitalised to remove case sensitivity of the search
	transform(productModelCapital.begin(), productModelCapital.end(), productModelCapital.begin(),(int (*)(int))toupper);
	listTitle =listingsDocument["title"].GetString();
	listTitleCapital=listTitle;
	//Information is capitalised to remove case sensitivity of the search
	transform(listTitleCapital.begin(), listTitleCapital.end(), listTitleCapital.begin(),(int (*)(int))toupper);





	//check if the manafacturer name in the list contains the manafacturer name in the products as a substring, either in list title or in listmanafacturer information
	foundMatch= listTitleCapital.find(productManafacturerCapital);
 	if (foundMatch != std::string::npos)
 	   {
 	        manafacturerIspressent=1;
 	   }
 	   else
 	   {
        manafacturerIspressent=0;
 	   }
	foundMatch1= listManafacturerCapital.find(productManafacturerCapital);
	 if (foundMatch1 != std::string::npos)
	    {
             manafacturerIspressent=1;
   	    }
    	else
    	{
          manafacturerIspressent=0;
    	}

	/*manafacturerIspressent = (  contains( listTitleCapital,productManafacturerCapital)
							||
					(contains( listManafacturerCapital,productManafacturerCapital))
							);
*/
	if(manafacturerIspressent)
	{
	manafacturerIspressent=  (   containsOnlyExactword( listTitleCapital,productManafacturerCapital)
							||
					( containsOnlyExactword( listManafacturerCapital,productManafacturerCapital))
							);

}



	foundMatch=  listTitleCapital.find(productModelCapital);
	 if (foundMatch != std::string::npos)	
	    {
             modelIspressent=1;
    	    }
   	 else
   	 {
          modelIspressent=0;
   	 }

	
	if(modelIspressent)
	{

	modelIspressent = ( containsOnlyExactword( listTitleCapital,productModelCapital)  );

	}

	productsFileLineString=productsFileLine;
	foundMatch=  productsFileLineString.find( "family");
 	if (foundMatch != std::string::npos)
       {
        familyInformationIsGiven=1;    // The product is searched for has a valid family information given
        }
       else
       {
        familyInformationIsGiven=0;
       }


	 

		if(familyInformationIsGiven)
		{
 
		productFamily =productsDocument["family"].GetString();
		productFamilyCapital=productFamily;
		//Information is capitalised to remove case sensitivity of the search
		transform(productFamilyCapital.begin(), productFamilyCapital.end(), productFamilyCapital.begin(),(int (*)(int))toupper);
		foundMatch=listTitleCapital.find(productFamilyCapital);
		 if (foundMatch != std::string::npos)
   		 {
     		  familyIspressent=1;    // The product is searched for has a valid family information given
    		}
    		else
   		 {
    		    familyIspressent=0;
    		}


 
	if(familyIspressent)
	{

		familyIspressent=containsOnlyExactword( listTitleCapital,productFamilyCapital);

	}

		}
	// The case wher the product has a valid family information and a match is found
	if( ( manafacturerIspressent && modelIspressent && familyInformationIsGiven  && familyIspressent ) || ( manafacturerIspressent &&        modelIspressent &&   !familyInformationIsGiven   )     )
		{

		system ("clear");             
		TotalNumberOfMatchesFound+=1;  // Total number of matches found for all the products searched so  far
		NumberOfMatches+=1;   	       // Number of matches found in the listings list for the current product searched for

		jsoniserObject.jsoniseData();  // Jsonise the product information for the current product searched for

		std::cout << endl<<endl<<endl<<endl<<endl<<endl<<"\033[36m"<<"Scanning the document "<<"\033[0m";   
		displayMap=string(displayMap)+string("|");  //Display bar
		display+=1;
		if(display ==30)
		{
		display =0;
		displayMap="";
		}
	std::cout <<"\033[1m\033[33m"<<displayMap<<"\033[0m";
	std::cout << endl<<"Current total matches "<< TotalNumberOfMatchesFound<<std::endl;


		if(NumberOfMatches==1)   	// Only one item in the listings list matched for  a specic product being searched for
			{
	 		matchedList=listingsFileLine;
			}

		else if(NumberOfMatches > 1)   // More than one item in the listings list matched for  a specic product being searched for
			{

			matchedList=matchedList+string(",")+listingsFileLine;
			}

     		 }


   	 }

   }
	std::cout << "SCANNING COMPLETE"<<std::endl;

	std::cout << "TOTAL NUMBER OF MATCHES FOUND ARE : "<< TotalNumberOfMatchesFound <<std::endl;
	std::cout << "NUMBER OF ITEMS CHECKED IN PRODUCT LIST: "<< TotalNumberOfItemsInProductlistChecked <<std::endl;
 
}


bool  Matcher::containsOnlyExactword(const std::string& sentence, const std::string& word)
{
        size_t pos = 0;
	pos=   sentence.substr(pos).find(word);
        // Find the start of 'word' in 'sentence'.
      //  while ((pos = sentence.substr(pos).find(word)) ) {
                // Make sure it's actually a word (e.g. "rain" could be part of "drain").
                // isalpha checks if the given character is in the alphabet. Here we check
                // if the characters before and after 'word' are alphabet characters. If neither
                // of them is an alphabet character then we've found a whole word.
                if (!(isalpha(sentence[pos - 1])) && !(isalpha(sentence[pos + word.size() ])))
                        return true;
     //   }
        // If we get to here then we didn't find any instance of 'word' that was a whole word.
        return false;
}




