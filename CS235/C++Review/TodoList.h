#ifndef TODOLIST_H
#define TODOLIST_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#include "TodoListInterface.h"

class TodoList : public TodoListInterface {
	private:
	vector<string> todoList;
	vector<string> todoDates;
	

	public:
	TodoList(){
		cout << "\nConstructor Accessed" << endl;
		ifstream inFS;
		inFS.open("TODOList.txt");
		if(inFS.is_open()){
			string line;
			while(getline(inFS, line)){
				cout << "\t" << line << endl;
				todoDates.push_back(line);
				getline(inFS,line);
				cout << "\t" << line << endl;
				todoList.push_back(line);
			}
		}else{
			cout << "failed to open file" << endl;
		}
		inFS.close();
	} 
	~TodoList(){
		cout << "\nDestructor Accessed" << endl;
		ofstream outFS;
		outFS.open("TODOList.txt");
		if(outFS.is_open()){
			//cout << "File opened" << endl;
			for(int i = 0; i < todoDates.size(); i++){
				outFS << todoDates.at(i) << endl;
				outFS << todoList.at(i) << endl;
			}
		}

		outFS.close();
		//cout << "file closed" << endl;
	}
	
	void add(string _duedate, string _task);
	
	int remove(string _task);
	
	void printTodoList();
	
	void printDaysTasks(string _date);

};


#endif