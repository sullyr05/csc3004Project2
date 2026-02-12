/* Bible class function definitions
 * Computer Science, MVNU
 * CSC-3004 Introduction to Software Development
 *
 * NOTE: You may add code to this file, but do not
 * delete any code or delete any comments.
 *
 * STUDENT NAME: Solomon Robinson
 */

#include "Ref.h"
#include "Verse.h"
#include "Bible.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Default constructor
Bible::Bible()
{ 
   infile = "/home/class/csc3004/Bibles/web-complete";
}

// Constructor – pass bible filename
Bible::Bible(const string s) { infile = s;}

// REQUIRED: lookup finds a given verse in this Bible
Verse Bible::lookup(Ref ref, LookupResult& status)
{ 
   // TODO: scan the file to retrieve the line that holds ref ...
   if(!instream.is_open()){
      instream.open(infile);
      if (!instream){ //if opening file fails
         status = OTHER;
         return Verse();
      }
   }

   string line;

   while (getline(instream , line)) { //get line fancy

	   Verse aVerse(line);
	   
      // logical test to see if the first line contains the reference we are looking for,
      // if not we move on to the next line until we match reference
	   if (aVerse.getRef() == ref){
		   status = SUCCESS;
         return aVerse; 
	   }
   }
   status = NO_VERSE; //no verse found
	return Verse(); // default to be returned
   // create and return the verse object
   //Verse aVerse;   // default verse, to be replaced by a Verse object
	                // that is constructed from a line in the file
}

// REQUIRED: Return the next verse from the Bible file stream if the file is open.
// If the file is not open, open the file and return the first verse.
Verse Bible::nextVerse(LookupResult& status)
{
   if (!instream.is_open()){
      instream.open(infile);
      string firstLine;
      getline(instream, firstLine);
      return Verse(firstLine); // return first line if file stream is not open
   }

   string line;

   if (getline(instream, line)){ //get next line and preserve file stream for multiple verse retrieval
      status = SUCCESS;
      return Verse(line);
   }
   else {// end of file
      status = OTHER;
      return Verse();
   }
}

// REQUIRED: Return an error message string to describe status
string Bible::error(LookupResult status)
{
   if (status == SUCCESS)
      return "Success!";
   else if (status == NO_BOOK)
      return "Error: Book not found!";
   else if (status == NO_CHAPTER)
      return "Error: Chapter not found!";
   else if (status == NO_VERSE)
      return "Error! Verse not found";
   else 
      return "Unknown Error";
}

void Bible::display()
{
   cout << "Bible file: " << infile << endl;
}
	


// OPTIONAL access functions
// OPTIONAL: Return the reference after the given ref
Ref Bible::next(const Ref ref, LookupResult& status)
{
   return ref;
}

// OPTIONAL: Return the reference before the given ref
Ref Bible::prev(const Ref ref, LookupResult& status)
{
   return ref;
}