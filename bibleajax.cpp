/* Demo server program for Bible lookup using AJAX/CGI interface
 * By James Skon, Febrary 10, 2011
 * updated by Bob Kasper, January 2020
 * updated by Deborah Wilson, February 2026
 * Mount Vernon Nazarene University
 *
 * This sample program works using the cgicc AJAX library to
 * allow live communication between a web page and a program running on the
 * same server that hosts the web server.
 *
 * This program is run by a request from the associated html web document.
 * A Javascript client function invokes an AJAX request,
 * passing the input form data as the standard input string.
 *
 * The cgi.getElement function parses the input string, searching for the matching
 * field name, and returing a "form_iterator" oject, which contains the actual
 * string the user entered into the corresponding field. The actual values can be
 * accessed by dereferencing the form iterator twice, e.g. **verse
 * refers to the actual string entered in the form's "verse" field.
 *
 * STUDENT NAME: Solomon Robinson 
 */
#include "Ref.h"
#include "Verse.h"
#include "Bible.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

/* Required libraries for AJAX to function */
#include "/home/class/csc3004/cgicc/Cgicc.h"
#include "/home/class/csc3004/cgicc/HTTPHTMLHeader.h"
#include "/home/class/csc3004/cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;

int main()
{
   /* A CGI program must send a response header with content type
    * back to the web client before any other output.
    * For an AJAX request, our response is not a complete HTML document,
    * so the response type is just plain text to insert into the web page.
    */
   cout << "Content-Type: text/plain\n\n";

   Cgicc cgi;  // create object used to access CGI request data

   // GET THE INPUT DATA
   // browser sends us a string of field name/value pairs from HTML form
   // retrieve the value for each appropriate field name
   form_iterator st = cgi.getElement("search_type");
   form_iterator book = cgi.getElement("book");
   form_iterator chapter = cgi.getElement("chapter");
   form_iterator verse = cgi.getElement("verse");
   form_iterator nv = cgi.getElement("num_verse");

   // Convert and check input data

   // TODO: OTHER INPUT VALUE CHECKS ARE NEEDED ... but that's up to you!	

   /* SEND BACK THE RESULTS
    * Finally we send the result back to the client on the standard output stream
    * in HTML text format.
    * This string will be inserted as is inside a container on the web page,
    * so we must include HTML formatting commands to make things look presentable!
    */      
   /* TODO: PUT CODE HERE TO CALL YOUR BIBLE CLASS FUNCTIONS
    *        TO LOOK UP THE REQUESTED VERSES
    */
   Bible webBible("/home/class/csc3004/Bibles/web-complete"); // create Bible object to access the bible file
   int bookNum = book->getIntegerValue();
   int verseNum = verse->getIntegerValue(); //assign values from form iterators to variables for creation of ref object
   int chapterNum = chapter->getIntegerValue();
   int numOfVerses = nv->getIntegerValue();
   LookupResult result;

   Ref ref(bookNum, chapterNum, verseNum); //create ref object from form input values
   Verse myVerse = webBible.lookup(ref,result); //lookup verse

   if (ref.isRefValid(ref) && result == SUCCESS){ //if we have a valid reference and the verse was found, display the verse
      myVerse.display();

      for (int i = 1; i < numOfVerses; i++){ //implementation for retrieval of multiple verses
      Verse tempV = myVerse;
      myVerse = webBible.nextVerse(result);
      if (myVerse.getRef().getChapter() != tempV.getRef().getChapter()){ //newline between chapters
         cout << "<br><br>\n";
      }
      cout << "<br>";
      myVerse.display();
    }
   }
   else if (ref.getChapter() <= 0 || ref.getVerse() <= 0){ //check for positive integers
      cout << "<p> You must enter a positive integer for chapter and verse numbers. </p>" << endl;
   }
   else{ //otherwise display an error message
      cout << "<p> " << webBible.error(result) << "\n There is no verse " << 
      verseNum << " in chapter " << chapterNum << " of the book of " << ref.getBookName() << ".</p>" 
      << endl;
    }
   return 0;
}
