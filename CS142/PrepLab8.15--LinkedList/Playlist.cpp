//
// Created by Chase Ford on 5/29/20.
//

#include "Playlist.h"

PlaylistNode::PlaylistNode(string IdIn, string sName, string aName, int length) {
    uniqueID = IdIn;
    songName = sName;
    artistName = aName;
    songLength = length;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nextNode) {
    PlaylistNode* tempPtr = this->GetNext();
    this->SetNext(nextNode);
    nextNode->SetNext(tempPtr);
}

void PlaylistNode::SetNext(PlaylistNode *nextNode) {
    this->nextNodePtr = nextNode;
}

string PlaylistNode::GetID() {
    return this->uniqueID;
}

string PlaylistNode::GetSongName() {
    return this->songName;
}

string PlaylistNode::GetArtistName() {
    return this->artistName;
}

int PlaylistNode::GetSongLength() {
    return this->songLength;
}

PlaylistNode *PlaylistNode::GetNext() {
    return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}




