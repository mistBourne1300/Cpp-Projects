//
// Created by Chase Ford on 6/1/20.
//
#pragma once
#ifndef LAB8PLAYLISTS_PLAYLIST_H
#define LAB8PLAYLISTS_PLAYLIST_H
#include <vector>
using namespace std;
#include "Song.cpp"


class Playlist {
public:
    explicit Playlist(const string &name = "no_init");

    string GetPlaylistName();

    void AddSong(Song* song_ptr);

    void RemSong(int songIndex);

    void RemSong(Song* songToRemove);

    void PlayThisPlaylist();

    void PrintPlaylist();

    Song* GetSong(int index);

private:
    vector<Song*> songPlaylist;
    string playlistName;

};


#endif //LAB8PLAYLISTS_PLAYLIST_H
