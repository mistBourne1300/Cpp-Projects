#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

void SortPropertiesByTaxesDue(vector<Property*>& listOfProperties);

int main() {
    cout << "starting..." << endl;
    vector<Property*> listOfProperties;

    string fileToRead, fileToWrite;
    ifstream inFS;
    ofstream outFS;
    ostringstream outSS;

    cout  << "Where should I read the data from: ";
    getline(cin , fileToRead);
    cout << endl;

    inFS.open(fileToRead.c_str());
    if (!inFS.is_open()){
        cout << "Failed to read file " << fileToRead << endl;
        return 1;
    }

    while (!inFS.eof()){
        string propType;
        inFS >> propType;
        if (propType == "Residential"){
            //property is residential
            //will have the format
            //Residential yes 200000 yes 42-Iris-Way
            string isRental;
            int estValue;
            string isOccupied;
            string propID;

            inFS >> isRental >> estValue >> isOccupied >> propID;

            //cout << endl << isRental << endl << estValue << endl << isOccupied << endl << propID << endl << endl;

            Residential* currProperty = new Residential(isRental, estValue, isOccupied, propID);
            listOfProperties.push_back(currProperty);

        } else{
            //property is commercial
            //will have the format
            //Commercial no 1234567 yes 20.5 350-Sea-Towers

            string isRental;
            int estValue;
            string isDeductible;
            double taxDeducRate;
            string propID;

            inFS >> isRental >> estValue >> isDeductible >> taxDeducRate >> propID;

            //cout << endl << isRental << endl << estValue << endl << isDeductible << endl << taxDeducRate << endl << propID << endl;

            Commercial* currProperty = new Commercial(isRental, estValue, isDeductible, taxDeducRate, propID);
            listOfProperties.push_back(currProperty);


        }
    }
    inFS.close();

    cout << "All properties:" << endl;
    for (Property* property  : listOfProperties){
        cout << property->ToString() << endl;
    }
    cout << endl;

    cout << "TAX REPORT:" << endl;
    for (Property* currProp : listOfProperties){
        cout << currProp->ComputeTaxes() << endl;
    }
    cout << endl;

    cout << "Where should I write the report (just press return to skip): ";
    getline(cin, fileToWrite);
    cout << endl;

    outFS.open(fileToWrite.c_str());
    /*if(!outFS.is_open()){
        cout << "Failed to write to file " << fileToWrite << endl;
        return 1;
    }*/

    outFS << "TAX REPORT:" << endl;
    for (Property* currProp : listOfProperties){
        outFS << currProp->ComputeTaxes() << endl;
    }
    outFS.close();
    cout << endl;

    SortPropertiesByTaxesDue(listOfProperties);

    cout << "SORTED VERSION:" << endl;
    cout << endl;
    cout << "TAX REPORT:" << endl;
    for (Property* currProp : listOfProperties){
        cout << currProp->ComputeTaxes() << endl;
    }
    cout << endl;



    return 0;
}

void SortPropertiesByTaxesDue(vector<Property*>& listOfProperties){
    vector<Property*> sortedListOfProperties;

    while(!listOfProperties.empty()){
        Property* lowProperty = listOfProperties.at(0);
        int lowPropertyIndex = 0;
        //find the lowest tax valued property
        for(unsigned int i = 0; i < listOfProperties.size(); i++){
            if(lowProperty->GetTaxValue() > listOfProperties.at(i)->GetTaxValue()){
                lowProperty = listOfProperties.at(i);
                lowPropertyIndex = i;
            }
        }

        //append the lowest valued property to the sorted list
        sortedListOfProperties.push_back(lowProperty);
        listOfProperties.erase(listOfProperties.begin() + lowPropertyIndex);
    }
    listOfProperties = sortedListOfProperties;
}