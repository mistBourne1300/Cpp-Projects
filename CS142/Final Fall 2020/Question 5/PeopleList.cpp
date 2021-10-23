//
// Created by Chase Ford on 12/8/20.
//

#include "PeopleList.h"
#include "Person.h"
#include <iostream>

using namespace std;

void PeopleList::Add(Person toAdd){
    //determine where to put the new person...
    unsigned int indexToInsertAt = 0;

    //special case -- no people in the list yet
    if(people.size() == 0){
        indexToInsertAt = 0;
    }
        //find the correct location, which is the position where the
        //next element in the list is "bigger"
    else{
        while(indexToInsertAt < people.size() && toAdd.LessThan(people.at(indexToInsertAt))){
            indexToInsertAt++;
        }
    }
    people.insert(people.begin() + indexToInsertAt, toAdd);
}

void PeopleList::PrintList(){
    for(unsigned int i = 0; i < people.size(); i++){
        cout << people.at(i).Name() << " " << people.at(i).Age() << endl;
    }
}

int PeopleList::Size(){
    return people.size();
}
