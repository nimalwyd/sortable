
# About the project

Project done by Nimal krishna for company sortable on 31/12/2017 in C++(in Linux environmet)

## Purpose of the project

This project is to search for a specific list item in the 'listings.txt' for a  match of any products in the 'products.txt'.In both files informations are stored in JSON form. 

The language used for the project is C++, in linux development environment. Rapidjson is used to parse the json data in both files.Search result is stored in the results.txt in JOSN form.

Class Jsoniser is used for this purpose.Search results are made more accurate by removing the case sensitivity and checking for the search word is contained in a longer string(eg rain in drain as a false match), and also  based on the informations given in the product searched for (for some products family information is given, where as for some not. 

So whenever family  information is given in the product to be searched for , a match of family is made a must condition for a sucessful match. In other cases family information is not used to find a match.)

### Prerequisites

Linux os 

All other dependencies are installed by the shell script if not installed

## Running the tests

To run this project,
1. clone this repo
2. cd to the cloned repo
3. run the below command
```
sudo ./go.sh
```
## Project status

```
completed
```

## Built With

* [Linux]
* [C++]
* [JSON]
* [shell scripting]

## Author

* **Nimal krishna** - *14/12/2017*
