#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Document.h
class Document{
   private:
      string name;
      string extension;
      string contents;
   public:
      Document(string nameIn, string extensionIn, string contentsIn);
      string GetName();
      void Rename(string newDocumentName);
      string GetExtension();
      string GetContents();
      void Print();

};

/*1
MainLab1
cpp
#include <iostream> ....
1
REL_A_131_Paper
doc
In the Book of Mormon, one of the main...
1
American-Heritage-Study-Guide
doc
The Spanish Armada was a...
1
Physical_Science_100
ppt
Slides for Physical Science Presentation...
4
5*/

//Document.cpp
Document::Document(string nameIn, string extensionIn, string contentsIn){
   name = nameIn;
   extension = extensionIn;
   contents = contentsIn;
}
string Document::GetName(){
   return name;
}
void Document::Rename(string newDocumentName){
   name = newDocumentName;
}
string Document::GetExtension(){
   return extension;
}
string Document::GetContents(){
   return contents;
}
void Document::Print(){
   cout << "Name: " << name << "." << extension << endl;
   cout << "Contents: " << contents << endl;
}

//main.cpp----------
void DisplayMenu(){
   cout << "Choose an option below: "<< endl;
   cout << "1. Add a document to your list"<< endl;
   cout << "2. Rename one of your documents"<< endl;
   cout << "3. Share one of your documents with your friend"<< endl;
   cout << "4. Display all of the documents"<< endl;
   cout << "5. Quit"<< endl << endl;
}

// Modify the main function to handle each menu option
// Consider creating a new function (above main) per menu option
int main(){
   const int ADD_DOCUMENT_OPTION = 1;
   const int RENAME_DOCUMENT_OPTION = 2;
   const int SHARE_YOUR_DOCUMENT_OPTION = 3;
   const int DISPLAY_ALL_DOCUMENTS_OPTION = 4;
   const int QUIT_OPTION = 5;

   int option;
   DisplayMenu();
   cin >> option;

   while(option != QUIT_OPTION){

      if(option == ADD_DOCUMENT_OPTION){
         cout << "Sorry, not implemented." << endl;
      }
      else if(option == RENAME_DOCUMENT_OPTION){
         cout << "Sorry, not implemented." << endl;
      }
      else if(option == SHARE_YOUR_DOCUMENT_OPTION){
         cout << "Sorry, not implemented." << endl;
      }
      else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){
         cout << "Sorry, not implemented." << endl;
      }

      cout << endl << "Enter option: " << endl;
      cin >> option;
      // cout << option << endl;
   }
   return 0;
}
