//
// Created by Chase Ford on 12/8/20.
//

#include "Person.h"

Person::Person(string newName, int newAge){
    name = newName;
    age = newAge;
    if(age < 0){
        age = 0;
    }
}

string Person::Name(){
    return name;
}

void Person::Rename(string newName){
    name = newName;
}

int Person::Age(){
    return age;
}

void Person::SetAge(int newAge){
    age = newAge;
}

bool Person::LessThan(Person compareTo){
    if(compareTo.age < age){
        return true;
    }
    else{
        return false;
    }
}