//
// Created by Chase Ford on 12/8/20.
//

#ifndef QUESTION_5_PERSON_H
#define QUESTION_5_PERSON_H


#include <string>

using namespace std;

class Person{
public:
    Person(string newName, int newAge);
    string Name();
    void Rename(string newName);
    int Age();
    void SetAge(int newAge);
    bool LessThan(Person compareTo);

private:
    int age;
    string name;
};




#endif //QUESTION_5_PERSON_H
