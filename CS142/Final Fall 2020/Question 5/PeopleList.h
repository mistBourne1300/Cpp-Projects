//
// Created by Chase Ford on 12/8/20.
//

#ifndef QUESTION_5_PEOPLELIST_H
#define QUESTION_5_PEOPLELIST_H



#include <vector>
#include "Person.h"

using namespace std;

class PeopleList{
public:
    void Add(Person toAdd);
    void PrintList();
    int Size();

private:
    vector<Person> people;

};



#endif //QUESTION_5_PEOPLELIST_H
