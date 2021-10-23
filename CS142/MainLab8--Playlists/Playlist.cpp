//
// Created by Chase Ford on 6/1/20.
//
#pragma once
#include "Playlist.h"

Playlist::Playlist(const string &name) {
    this->playlistName = name;
}

string Playlist::GetPlaylistName() {
    return playlistName;
}

void Playlist::AddSong(Song *song_ptr) {
    songPlaylist.push_back(song_ptr);
}

void Playlist::PlayThisPlaylist() {
//cout << "playing Playlist" << playlistName << endl;
    for (Song* currSong : songPlaylist){
        currSong->PlaySong();
    }
}

void Playlist::RemSong(int songIndex) {
    songPlaylist.erase(songPlaylist.begin() + songIndex);
}

void Playlist::PrintPlaylist() {
    for (unsigned int i = 0; i < songPlaylist.size(); i++){
        cout << "  " << i << ": " << songPlaylist.at(i)->GetSongTitle() << endl;
    }
}

void Playlist::RemSong(Song *songToRemove) {
    for (unsigned int i = 0; i < songPlaylist.size(); i++){
        //compare the pointers of the songs. not the titles themselves,
        // that would remove two same-titled songs inadvertently
        if (songPlaylist.at(i) == songToRemove){
            songPlaylist.erase(songPlaylist.begin() + i);
        }
    }
}

Song *Playlist::GetSong(int index) {
    return songPlaylist.at(index);
}
