//
// Created by Chase Ford on 6/1/20.
//
#pragma once
#ifndef LAB8PLAYLISTS_SONG_H
#define LAB8PLAYLISTS_SONG_H
#include <string>
#include <iostream>
using namespace std;


class Song {
public:
    Song(string title = "no_init", string firstLine = "no_init");
    string GetSongTitle();
    string GetFirstLine();
    int GetPlayCount();

    void SetSongTitle(const string& title);
    void SetFirstLine(const string& firstLine);

    void PlaySong();

private:
    string songTitle;
    string firstLine;
    int playCount;



};


#endif //LAB8PLAYLISTS_SONG_H
