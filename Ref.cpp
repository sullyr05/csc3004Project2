/* Ref class function definitions
 * Computer Science, MVNU
 * CSC-3004 Introduction to Software Development
 *
 * NOTE: You may add code to this file, but do not
 * delete any code or delete any comments.
 *
 * STUDENT NAME: Solomon Robinson
 */

#include "Ref.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<BookInfo> Ref::bookInfo = { //Create vector instead of array so we know how many chapters are in each book
   {"Genesis",50}, {"Exodus",40}, {"Leviticus",27}, {"Numbers",36}, {"Deuteronomy",34},
   {"Joshua",24}, {"Judges",21}, {"Ruth",4}, {"1 Samuel",31}, {"2 Samuel",24},
   {"1 Kings",22}, {"2 Kings",25}, {"1 Chronicles",29}, {"2 Chronicles",36},
   {"Ezra",10}, {"Nehemiah",13}, {"Esther",10}, {"Job",42}, {"Psalms",150},
   {"Proverbs",31}, {"Ecclesiastes",12}, {"Song of Solomon",8}, {"Isaiah",66},
   {"Jeremiah",52}, {"Lamentations",5}, {"Ezekiel",48}, {"Daniel",12},
   {"Hosea",14}, {"Joel",3}, {"Amos",9}, {"Obadiah",1}, {"Jonah",4},
   {"Micah",7}, {"Nahum",3}, {"Habakkuk",3}, {"Zephaniah",3},
   {"Haggai",2}, {"Zechariah",14}, {"Malachi",4}, {"Matthew",28},
   {"Mark",16}, {"Luke",24}, {"John",21}, {"Acts",28}, {"Romans",16},
   {"1 Corinthians",16}, {"2 Corinthians",13}, {"Galatians",6}, {"Ephesians",6},{"Titus",3},
   {"Philippians",4}, {"Colossians",4}, {"1 Thessalonians",5}, {"2 Thessalonians",3}, {"1 Timothy",6}, {"2 Timothy",4},
   {"Philemon",1}, {"Hebrews",13}, {"James",5}, {"1 Peter",5}, {"2 Peter",3},
   {"1 John",5}, {"2 John",1}, {"3 John",1}, {"Jude",1}, {"Revelation",22}
}; 





/* GetNextToken - general routine for getting next token from a string
 * Parameters
 *    str - string to search. search is destructive, i.e., token is removed.
 *    delimiters - string, a list of characters to use a delimiters between tokens
 * Returns: string token (removed from str)
 */
string GetNextToken(string& str, const string& delimiters = " ")
{
   // Skip delimiters at beginning                                          
   string::size_type startPos = str.find_first_not_of(delimiters, 0);
  
   // Find position of delimiter at end of token                                           
   string::size_type endPos = str.find_first_of(delimiters, startPos);

   // Found a token, remove it from string, and return it                       
   string next = str.substr(startPos, endPos - startPos);
   string rest = str.substr(endPos - startPos + 1, string::npos);
   str = rest;
   return(next);
}

// Ref member functions

// Default constructor
Ref::Ref() {book = 0; chapter = 0; verse = 0;}  	

// Parse constructor - receives a line "34:5:7 text"
Ref::Ref(const string s)
{ 
   string rtext = s; // make local copy of string to avoid modifying parameter
   // parse the reference - notice, currently there is no error checking!
    
   // Get book number
   string strbook = GetNextToken(rtext,":");
   book = atoi(strbook.c_str());
    
   // Get the chapter number
   string strchap = GetNextToken(rtext,":");
   chapter = atoi(strchap.c_str());
    
   // Get the verse number
   string strverse = GetNextToken(rtext," ");
   verse = atoi(strverse.c_str());
}

// Construct Ref from three integers
Ref::Ref(const int b, const int c, const int v) 
{ 	
   book = b;
   chapter = c;
   verse = v;
}

// Accessors
int Ref::getBook() {return book;}	     // Access book number
int Ref::getChapter() {return chapter;}	 // Access chapter number
int Ref::getVerse() {return verse;};     // Access verse number


// REQUIRED: == comparison
bool Ref::operator==(const Ref & ref) const
{
   // TODO: implement comparison functions
   if (book == ref.book && chapter == ref.chapter && verse == ref.verse)
      return true;
   else 
      return false;
}

// OPTIONAL: define < and > comparisons

bool Ref::isRefValid(Ref ref){
   
/// we gonna use a vector instaed!
	return false;
}
// Display Reference
void Ref::display()
{ 	
   // TODO: modify display function to show book name instead of book number

   cout << " " << bookInfo[book-1].name << " " << chapter << ":" << verse;

}

