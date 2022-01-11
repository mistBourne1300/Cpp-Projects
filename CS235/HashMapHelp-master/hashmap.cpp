#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include "VectorMap.h"
#include "HashMap.h"
using namespace std;

list <string> lst;
int main(int argc, char **argv)
{
  if (argc < 2){
    cout << "Please provide a file name" << endl;
    return 0;
  }
  ifstream file(argv[1]);

  // Read data
  while (!file.eof()) {
    string word, nopunct="";
    file >> word;
    
    for(auto &c : word) { // Remove Punctuation      
      if (isalpha(c)) {
        nopunct +=c;       
      }
    }
    lst.push_back(nopunct);
  }
  clock_t oldtime, newtime; // To time the functions
  double seconds;
  oldtime = clock();
  VectorMap<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    //vector<string> tmp = wordmap[state];
    //cout <<"Got "<< tmp<<endl;
    state = *it;
  }
  
  
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 1000; i++) {
    int ind = rand() % wordmap[state].size();
    //cout << "index "<<ind;
    //cout << wordmap[state][ind] << " ";
    state = wordmap[state][ind];
  }
  //cout << endl;
  newtime = clock();
  seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
  cout << "Vector Map took "<<seconds<<endl;
  
  oldtime = clock();
  HashMap<string, vector<string>> hashwordmap;
  state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    hashwordmap[state].push_back(*it);
    //vector<string> tmp = wordmap[state];
    //cout <<"Got "<< tmp<<endl;
    state = *it;
  }
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 1000; i++) {
    int ind = rand() % hashwordmap[state].size();
    //cout << "index "<<ind;
    //cout << hashwordmap[state][ind] << " ";
    state = hashwordmap[state][ind];
  }
  //cout << endl;
  newtime = clock();
  seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
  cout << "Hash Map took "<<seconds<<endl;
}
