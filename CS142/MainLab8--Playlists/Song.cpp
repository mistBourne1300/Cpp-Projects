//
// Created by Chase Ford on 6/1/20.
//
#pragma once
#include "Song.h"

Song::Song(string title, string firstLine) {
    songTitle = title;
    this->firstLine = firstLine;
    playCount = 0;
}

string Song::GetSongTitle() {
    return songTitle;
}

string Song::GetFirstLine() {
    return firstLine;
}

int Song::GetPlayCount() {
    return playCount;
}

void Song::SetSongTitle(const string &title) {
    songTitle = title;
}

void Song::SetFirstLine(const string &firstLine) {
    this->firstLine = firstLine;
}

void Song::PlaySong() {
    cout << GetFirstLine() << endl;
    this->playCount++;
}
