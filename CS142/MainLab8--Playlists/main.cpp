//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>
#include "Playlist.cpp"

//TODO: Include your class files here


// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(std::vector<Song*>& songLibrary);
void ListSongsMenuOption(std::vector<Song*>& songLibrary);
void AddPlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists);
void AddSongToPlaylistMenuOption(std::vector<Song*>& songLibrary, std::vector<Playlist*>& listOfPlaylists);
void ListPlaylistsMenuOption(std::vector<Playlist*>& listOfPlaylists);
void PlayPlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists);
void RemovePlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists);
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists);
void RemoveSongFromLibraryMenuOption(std::vector<Song*>& songLibrary, std::vector<Playlist*>& listOfPlaylists);
void OptionsMenuOption(/*TODO: list any parameters here*/);
void QuitMenuOption(std::vector<Song*>& songLibrary, std::vector<Playlist*>& listOfPlaylists);

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    //TODO: Create vectors to hold the songs and playlists
    std::vector<Song*> songLibrary;
    std::vector<Playlist*> listOfPlaylists;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songLibrary);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(songLibrary);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(songLibrary, listOfPlaylists);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(songLibrary, listOfPlaylists);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption(/*TODO: list any arguments here*/);
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption(songLibrary, listOfPlaylists);
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption(/*TODO: list any arguments here*/);
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(std::vector<Song*>& songLibrary) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        Song* newSong = new Song(songName, firstLine);
        songLibrary.push_back(newSong);


        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(std::vector<Song*>& songLibrary) {

    for (Song* currSong : songLibrary){
        cout << currSong->GetSongTitle() << ": \""
             << currSong->GetFirstLine() << "\", " << currSong->GetPlayCount() << " play(s)." << endl;
    }
    cout << endl;
}

void AddPlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists) {

    string newPlaylistName = GetUserString("Playlist name: ");
    listOfPlaylists.push_back(new Playlist(newPlaylistName));
}

void AddSongToPlaylistMenuOption(std::vector<Song*>& songLibrary, std::vector<Playlist*>& listOfPlaylists) {
    int userPlaylistChoice;
    int userSongChoice;

    for (unsigned int i = 0; i < listOfPlaylists.size(); i++){
        cout << "  " << i << ": " << listOfPlaylists.at(i)->GetPlaylistName() << endl;
    }
    userPlaylistChoice = GetUserInt("Pick a playlist index number: ");

    for (unsigned int i = 0; i < songLibrary.size(); i++){
        cout << "  " << i << ": " << songLibrary.at(i)->GetSongTitle() << endl;
    }
    userSongChoice = GetUserInt("Pick a song index number: ");

    listOfPlaylists.at(userPlaylistChoice)->AddSong(songLibrary.at(userSongChoice));

    cout << endl;
}

void ListPlaylistsMenuOption(std::vector<Playlist*>& listOfPlaylists) {

    for (unsigned int i = 0; i < listOfPlaylists.size(); i++){
        cout << "  " << i << ": " << listOfPlaylists.at(i)->GetPlaylistName() << endl;
    }
    cout << endl;
}

void PlayPlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists) {
    int userPlaylistChoice;

    for (unsigned int i = 0; i < listOfPlaylists.size(); i++){
        cout << "  " << i << ": " << listOfPlaylists.at(i)->GetPlaylistName() << endl;
    }
    userPlaylistChoice = GetUserInt("Pick a playlist index number: ");


    cout << "Playing songs from playlist: " << listOfPlaylists.at(userPlaylistChoice)->GetPlaylistName() << endl;
    listOfPlaylists.at(userPlaylistChoice)->PlayThisPlaylist();

    cout << endl;
}

void RemovePlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists) {
    //TODO: Implement this menu option
    int userPlaylistChoice;

    for (unsigned int i = 0; i < listOfPlaylists.size(); i++){
        cout << "  " << i << ": " << listOfPlaylists.at(i)->GetPlaylistName() << endl;
    }
    userPlaylistChoice = GetUserInt("Pick a playlist index number to remove: ");
//cout << "deleting playlist at " << userPlaylistChoice << endl;

    delete listOfPlaylists.at(userPlaylistChoice);

    listOfPlaylists.erase(listOfPlaylists.begin() + userPlaylistChoice);

}

void RemoveSongFromPlaylistMenuOption(std::vector<Playlist*>& listOfPlaylists) {
    //TODO: Implement this menu option
    int userPlaylistChoice, userSongChoice;

    for (unsigned int i = 0; i < listOfPlaylists.size(); i++){
        cout << "  " << i << ": " << listOfPlaylists.at(i)->GetPlaylistName() << endl;
    }
    userPlaylistChoice = GetUserInt("Pick a playlist index number: ");

    listOfPlaylists.at(userPlaylistChoice)->PrintPlaylist();
    userSongChoice = GetUserInt("Pick a song index number to remove: ");

    listOfPlaylists.at(userPlaylistChoice)->RemSong(userSongChoice);
}

void RemoveSongFromLibraryMenuOption(std::vector<Song*>& songLibrary, std::vector<Playlist*>& listOfPlaylists) {
    //TODO: Implement this menu option
    int userSongChoice;
    Song* songToRemove;

    for (unsigned int i = 0; i < songLibrary.size(); i++){
        cout << "  " << i << ": " << songLibrary.at(i)->GetSongTitle() << endl;
    }
    userSongChoice = GetUserInt("Pick a song index number to remove: ");
    songToRemove = songLibrary.at(userSongChoice);

    for (unsigned int i = 0; i < listOfPlaylists.size(); i++){
        listOfPlaylists.at(i)->RemSong(songToRemove);
    }

    delete songToRemove;

    songLibrary.erase(songLibrary.begin() + userSongChoice);



}

void OptionsMenuOption(/*TODO: list any parameters here*/) {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption(std::vector<Song*>& songLibrary, std::vector<Playlist*>& listOfPlaylists) {
    std::cout << "Goodbye!" << std::endl;

    while (listOfPlaylists.size() > 0){
        delete listOfPlaylists.at(0);
        listOfPlaylists.erase(listOfPlaylists.begin());
    }
    while (songLibrary.size() > 0){
        delete songLibrary.at(0);
        songLibrary.erase(songLibrary.begin());
    }

}
