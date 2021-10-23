#include <iostream>
#include <string>
using namespace std;
#include "Playlist.h"

void PrintMenu(string& playlistTitle);

char GetUserInput(string validInputs, string playlistTitle);


int main() {
    string playlistTitle;
    char userChoice;
    const string VALID_OPTIONS = "adcstoq";
    int numSongs = 0;

    PlaylistNode* head = new PlaylistNode();
    PlaylistNode* currNode = nullptr;
    PlaylistNode* lastNode = head;

    cout << "Enter playlist's title: ";
    getline(cin, playlistTitle);
    cout << endl;



    do {
        currNode = head;

        userChoice = GetUserInput(VALID_OPTIONS, playlistTitle);

        if(userChoice == 'a'){ //add song to playlist
            string ID;
            string name;
            string artist;
            int length;

            cin.ignore();

            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID: ";
            getline(cin, ID);
            cout << endl;

            cout << "Enter song's name: ";
            getline(cin, name);
            cout << endl;

            cout << "Enter artist's name: ";
            getline(cin, artist);
            cout << endl;

            cout << "Enter song's length (in seconds): ";
            cin >> length;
            cout << endl;

            currNode = new PlaylistNode(ID, name, artist, length);
            lastNode->InsertAfter(currNode);
            lastNode = currNode;

            numSongs++;

        }

        else if(userChoice == 'd'){ //remove song
            cout << "REMOVE SONG" << endl;
            string ID;

            cin.ignore();
            cout << "Enter song's unique ID: ";
            getline(cin, ID);
            cout << endl;

            while (currNode != nullptr){
                if(lastNode == currNode){
                    cout << "Could not find song" << endl;
                    break;
                }
                if(currNode->GetNext()->GetID() == ID){
                    cout << "\"" << currNode->GetNext()->GetSongName() << "\" removed." << endl;
                    currNode->SetNext(currNode->GetNext()->GetNext());
                    break;
                }

                currNode = currNode->GetNext();


            }

        }

        else if(userChoice == 'c'){ //change position of song
            cout << "CHANGE POSITION OF SONG" << endl;

            PlaylistNode* tempNode = nullptr;
            int iterator;
            int tempNodeIter;
            do{
                cout << "Enter song's current position: ";
                cin >> iterator;
                cout << endl;
            }while ((iterator > numSongs) || (iterator <= 0));

            cout << "Enter new position for song: ";
            cin >> tempNodeIter;
            cout << endl;

            //get the node to be moved.
            for(int i = 0; i < iterator; i++){
                currNode = currNode->GetNext();
            }
            //currNode->PrintPlaylistNode();

            if(tempNodeIter >= numSongs){ //move to end of list
                cout << "\"" << currNode->GetSongName() << "\" moved to position " << numSongs << endl;
                //get the song before the currNode
                PlaylistNode* prevNode = head;
                for (int i = 0; i < (iterator - 1); i++){
                    prevNode = prevNode->GetNext();
                }

                //take the previous node, point it to the next
                //point the last node to the currNode
                //assign last node to curr node (now the last node)
                prevNode->SetNext(prevNode->GetNext()->GetNext());
                lastNode->SetNext(currNode);
                lastNode = currNode;
                lastNode->SetNext(nullptr);


            }else if (tempNodeIter <= 1){ //move to front of list
                cout << "\"" << currNode->GetSongName() << "\" moved to position 1" << endl;
                //get the song before the currNode
                PlaylistNode* prevNode = head;
                for (int i = 0; i < (iterator - 1); i++){
                    prevNode = prevNode->GetNext();
                }

                //take the previous node, point it to the next
                //point curr to head->GetNext()
                //point head to curr
                prevNode->SetNext(prevNode->GetNext()->GetNext());
                currNode->SetNext(head->GetNext());
                head->SetNext(currNode);

            }else if(iterator < tempNodeIter){//move to position tempNodeIter
                cout << "\"" << currNode->GetSongName() << "\" moved to position " << tempNodeIter << endl;

                //get the song before the currNode
                PlaylistNode* prevNode = head;
                for (int i = 0; i < (iterator - 1); i++){
                    prevNode = prevNode->GetNext();
                }

                //get the old node for the move position
                tempNode = head;
                for (int i = 0; i < tempNodeIter; i++){
                    tempNode = tempNode->GetNext();
                }

                //point previous to the next node
                //point the currNode to the one after it's new position
                //point the tempNode node to the currNode
                prevNode->SetNext(currNode->GetNext());
                currNode->SetNext(tempNode->GetNext());
                tempNode->SetNext(currNode);


            }else {
                cout << "\"" << currNode->GetSongName() << "\" moved to position " << tempNodeIter << endl;

                //get the song before the currNode
                PlaylistNode* prevNode = head;
                for (int i = 0; i < (iterator - 1); i++){
                    prevNode = prevNode->GetNext();
                }

                //get the song before the new position
                PlaylistNode* prevTempNode = head;
                for (int i = 0; i < (tempNodeIter - 1); i++){
                    prevTempNode = prevTempNode->GetNext();
                }

                //point previous to the next node
                //point currNode to the new position's current placeholder
                prevNode->SetNext(currNode->GetNext());
                currNode->SetNext(prevTempNode->GetNext());
                prevTempNode->SetNext(currNode);


                //find the last node in the list, then set lastNode to that node
                currNode = head;
                while(currNode->GetNext() != nullptr){
                    currNode = currNode->GetNext();
                }
                lastNode = currNode;

            }


        }

        else if(userChoice == 's'){ //output songs by specific artist
            if(lastNode == head){
                cout << "Playlist is empty" << endl;
            }
            else {
                string artist;
                int iter = 0;

                cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
                cout << "Enter artist's name: ";
                cin.ignore();
                getline(cin, artist);
                cout << endl;

                while (currNode != nullptr){
                    if (currNode->GetArtistName() == artist){
                        cout << iter << "." << endl;
                        currNode->PrintPlaylistNode();
                        cout << endl;
                    }

                    iter++;
                    currNode = currNode->GetNext();
                }
            }




        }

        else if(userChoice == 't'){ //output total time of playlist
            if(lastNode == head){
                cout << "Playlist is empty" << endl;
            }
            else {
                cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
                int totTime = 0;
                while (currNode != nullptr){
                    totTime+=currNode->GetSongLength();
                    currNode = currNode->GetNext();
                }
                cout << "Total time: " << totTime << " seconds" << endl;
            }

        }

        else if(userChoice == 'o'){ //output full playlist
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if(lastNode == head){
                cout << "Playlist is empty" << endl;
            }
            else {
                int counter = 1;
                currNode = currNode->GetNext();
                while(currNode != nullptr){
                    cout << counter++ << "." << endl;
                    currNode->PrintPlaylistNode();
                    currNode = currNode->GetNext();
                    cout << endl;
                }
            }


        }


    }while (userChoice != 'q');

    return 0;
}


void PrintMenu(string& playlistTitle){

    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;

}

char GetUserInput(string validInputs, string playlistTitle){
    char userInput;

    do {
        PrintMenu(playlistTitle);
        cout << "\nChoose an option: ";
        cin >> userInput;
        cout << endl;
    }while (validInputs.find(userInput) == string::npos);
    return userInput;
}