//
// Created by Chase Ford on 5/29/20.
//

#ifndef PLAYLISTLINKEDLIST_PLAYLIST_H
#define PLAYLISTLINKEDLIST_PLAYLIST_H
#include <string>
#include <iostream>
using namespace std;

class PlaylistNode {
public:
    explicit PlaylistNode(string IdIn = "none", string sName = "none", string aName = "none", int length = 0);
    void InsertAfter(PlaylistNode* nextNode);
    void SetNext(PlaylistNode* nextNode);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};


#endif //PLAYLISTLINKEDLIST_PLAYLIST_H
