#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <fstream>
#include <queue>

using namespace std;

void print_vector(vector<string> & vector_to_print){
	for(vector<string>::iterator it = vector_to_print.begin(); it != vector_to_print.end(); it++){
		if(it != vector_to_print.begin()){
			cout << ", ";
		}
		cout << *it;
	}
	cout << endl;
}

void word_vector(vector<string> & all_words, string filename){

	ifstream inFS;
	inFS.open(filename);
	if(!inFS.is_open()){
		cout << "failed to open file " << filename << ". terminating program" << endl;
		return;
	}
	cout << filename << " opened." << endl;
	string word;
	while(!inFS.eof()){
		inFS >> word;
		for(int i = 0; i < word.size(); i++){
			if(!isalpha(word[i])){
				word.erase(word.begin() +i);
			}
		}
		all_words.push_back(word);
	}
	inFS.close();
	cout << filename << "closed" << endl;
}







int main(int argc, char *argv[]){
	string newFilename = "";
	ofstream outFS;

	//********************     PART 1    ***********************


	//Checking to see if the program has the right arguments
	if(argc != 2){
		cout << "predict_text requires exactly one positional argument. your arguments:" << endl;
		for(int i = 0; i < argc; i++){
			cout << i << "/" << argc << ": " << argv[i] << endl;
		}
	}

	//opening text file for reading
	string filename = argv[1];
	ifstream inFS;
	inFS.open(filename);
	if(!inFS.is_open()){
		cout << "failed to open file " << filename << ". terminating program" << endl;
		return 1;
	}
	cout << filename << " opened." << endl;
	
	//reading unique words into a set
	string word;
	set <string> unique_words;
	while(!inFS.eof()){
		inFS >> word;
		for(int i = 0; i < word.size(); i++){
			if(!isalpha(word[i])){
				word.erase(word.begin() +i);
			}
		}
		unique_words.insert(word);
	}
	inFS.close();
	cout << filename << " closed" << endl;
/*

	//opening a new file for writing
	newFilename = filename;
	newFilename.append("_set.txt");
	outFS.open(newFilename);
	if (!outFS.is_open()){
		cout << "failed to open file " << newFilename << ". terminating program." << endl;
		return 1;
	}
	cout << newFilename << " opened." << endl;


	//writing set to new file: [filename]_set.txt
	for (set<string>::iterator it = unique_words.begin(); it!=unique_words.end(); it++){
		outFS << *it << endl;
	}
	outFS.close();
	cout << newFilename << " closed." << endl;
	//cout << "Size: " << unique_words.size() << endl;
*/

	//*******************    PART 2    **********************************
/*	
	//opening [filename] for reading
	newFilename = filename + "_vector.txt";
	outFS.open(newFilename);
	if(!outFS.is_open()){
		cout << "failed to open file " << newFilename << ". terminating program." << endl;
		return 1;
	}
*/
	//getting a vector of all words
	vector<string> all_words;
	word_vector(all_words, filename);
/*
	for (vector<string>::iterator it = all_words.begin(); it != all_words.end(); it++){
		outFS << *it << endl;
	}
	outFS.close();
	cout << newFilename << " closed" << endl;
*/
	//***********************    PART 3    ************************


	//getting a map from one word to its successor
	map<string, string> wordmap;
	string previous = "";
	for(vector<string>::iterator it = all_words.begin(); it != all_words.end(); it++){
		wordmap[previous] = *it;
		previous = *it;
	}

/*
	//outputting our map to a file
	newFilename = filename + "_map.txt";
	outFS.open(newFilename);
	cout << newFilename << " opened." << endl;
	if(!outFS.is_open()){
		cout << "failed to open file " << newFilename << ". terminating program." << endl;
		return 1;
	}
	for (map<string, string>::iterator it = wordmap.begin(); it != wordmap.end(); it++){
		outFS << it->first << ", " << it->second << endl;
	}
	outFS.close();
	cout << newFilename << " closed." << endl;
*/

	//*****************    PART 4    **************************

	string state = "";
	cout << state << " ";
	for (int i = 0; i < 100; i++){
		cout << wordmap[state] << " ";
		state = wordmap[state];
	}
	cout << endl;


	//******************    PART 5    **************************

	map<string, vector<string> > vectormap;
	previous = "";
	for (vector<string>::iterator it = all_words.begin(); it != all_words.end(); it++){
		vectormap[previous].push_back(*it);
		previous = *it;
	}

	// state = "Nephi";
	// cout << state << ":" << endl;
	// print_vector(vectormap[state]);
/*
	//outputting vector map to file
	newFilename = filename + "_map_to_vector.txt";
	outFS.open(newFilename);
	cout << newFilename << " opened." << endl;
	if(!outFS.is_open()){
		cout << "failed to open file " << newFilename << ". terminating program." << endl;
		return 1;
	}
	for(map<string, vector<string> >::iterator it = vectormap.begin(); it != vectormap.end(); it++){
		outFS << it->first << ": [";
		for(vector<string>::iterator iter = it->second.begin(); iter != it->second.end(); iter++){
			if(iter != it->second.begin()){
				outFS << ", ";
			}
			outFS << *iter;
		}
		outFS << "]" << endl;
	}
	outFS.close();
	cout << newFilename << " closed." << endl;
*/
	

	srand(time(NULL));
	state = "";
	for(int i = 0; i < 100; i++){
		if(vectormap[state].empty()){
			state = "";
		}
		int index = rand() % vectormap[state].size();
		//cout << state << ": " << index << endl;
		cout << vectormap[state][index] << " ";
		state = vectormap[state][index];
	}
	cout << endl;


	//*********************    PART 6    *****************
	cout << "\n\n\n" << endl;
	const int M = 3;
	map<list<string>, vector<string> > multiwordvectormap;
	list<string> multistate;
	for (int i = 0; i < M; i++){
		multistate.push_back("");
	}

	for (vector<string>::iterator it = all_words.begin(); it != all_words.end(); it++){
		multiwordvectormap[multistate].push_back(*it);
		multistate.push_back(*it);
		multistate.pop_front();
	}

	multistate.clear();
	for (int i = 0; i < M; i++){
		multistate.push_back("");
	}

	for(int i = 0; i < 100; i++){
		if(multiwordvectormap[multistate].empty()){
			multistate.clear();
			for (int i = 0; i < M; i++){
				multistate.push_back("");
			}
		}
		int index = rand() % multiwordvectormap[multistate].size();
		cout << multiwordvectormap[multistate][index] << " ";
		multistate.push_back(multiwordvectormap[multistate][index]);
		multistate.pop_front();
	}



}