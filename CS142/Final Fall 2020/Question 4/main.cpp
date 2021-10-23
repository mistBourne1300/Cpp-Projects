#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 *
Enter option:
4
-------------------Your List------------------
Name: MainLab1.cpp
Contents: #include <iostream> ....
Name: REL_A_131_Paper.doc
Contents: In the Book of Mormon, one of the main...
Name: American-Heritage-Study-Guide.doc
Contents: The Spanish Armada was a...
Name: Physical_Science_100.ppt
Contents: Slides for Physical Science Presentation...
--------------Your Friend's List--------------
Name: American-Heritage-Study-Guide.doc
Contents: The Spanish Armada was a...
----------------------------------------------
 */

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

   vector<Document*> userDocuments;
   vector<Document*> friendsDocuments;

   int option;
   DisplayMenu();
   cin >> option;

   while(option != QUIT_OPTION){

      if(option == ADD_DOCUMENT_OPTION){
          cin.ignore();
          string docName, docExtenstion, docContents;
          cout << "Enter the document name:" << endl;
          getline(cin, docName);
          cout << "Enter the document extension:" << endl;
          getline(cin, docExtenstion);
          cout << "Enter the document content:" << endl;
          getline(cin, docContents);
          Document* newDoc = new Document(docName, docExtenstion, docContents);
          userDocuments.push_back(newDoc);
      }
      else if(option == RENAME_DOCUMENT_OPTION){
          int docIndex = 0;
          string newDocName;
          cout << "Enter the index of your document you want to rename:" << endl;
          cin >> docIndex;
          cin.ignore();
          cout << "Enter the updated name of the document:" << endl;
          getline(cin, newDocName);
          userDocuments.at(docIndex)->Rename(newDocName);
      }
      else if(option == SHARE_YOUR_DOCUMENT_OPTION){
          int docIndex = 0;
          cout << "Enter the index of your document you want to share:" << endl;
          cin >> docIndex;
          cin.ignore();
          friendsDocuments.push_back(userDocuments.at(docIndex));
      }
      else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){
          cout << "-------------------Your List------------------" << endl;
          for(int i = 0; i < userDocuments.size(); i++){
              userDocuments.at(i)->Print();
          }
          cout << "--------------Your Friend's List--------------" << endl;
          for(int i = 0; i < friendsDocuments.size(); i++){
              friendsDocuments.at(i)->Print();
          }
          cout << "----------------------------------------------" << endl;
      }

      cout << endl << "Enter option: " << endl;
      cin >> option;
   }

   while(userDocuments.size() > 0){
       delete userDocuments.at(0);
       userDocuments.erase(userDocuments.begin());
   }
   while(friendsDocuments.size() > 0){
       friendsDocuments.erase(friendsDocuments.begin());
   }
   return 0;
}
