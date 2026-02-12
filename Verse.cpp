/* Verse class function definitions
 * Computer Science, MVNU
 * CSC-3004 Introduction to Software Development
 *
 * NOTE: You may add code to this file, but do not
 * delete any code or delete any comments.
 *
 * STUDENT NAME: Solomon Robinson
 */

#include "Verse.h"
#include <iostream>

using namespace std;

// Default constructor
Verse::Verse()
{  	
   verseText = "Uninitialized Verse!";
   verseRef = Ref();
} 

// REQUIRED: Parse constructor - pass verse string from file
Verse::Verse(const string s)
{
   // TODO: use Ref constructor to create verseRef
   // store the remainder of the string in verseText
   
   // Find space inbetween reference # and actual verse text
   // This way we can split the verse into verseRef and verseText
   size_t fSpace = s.find(' ');
	verseRef = Ref(s);  //fixed!
   verseText = s.substr(fSpace + 1);
}  	

// REQUIRED: Accessors
string Verse::getVerse()
{
   return verseText;	   
}

Ref Verse::getRef()
{
   return verseRef;
}

// display reference and verse
void Verse::display()
{
   verseRef.display();
   cout << " " << verseText;
}
