#include <iostream>
#include <ios>
#include <iomanip>

#include "TodoList.cpp"

int main(int argc, char *argv[]) {
	TodoList myList;
	for(int i= 0; i<argc; i++){
		cout << i << "/" << argc << ": " << argv[i] << endl;
	}
	if(argc < 2){
		cout << "TODO requires more positional arguments:" << endl;
		cout << left << setw(25) << "\tadd [_duedate] \"_task\"" << "add task to list" << endl;
		cout << left << setw(25) << "\tremove \"_task\"" << "remove specified task" << endl;
		cout << left << setw(25) << "\tprintlist" << "prints todo list" << endl;
		cout << left << setw(25) << "\tprintday [day]" << "print tasks due on [day]" << endl;
		return 1;
	}
	string firstarg = argv[1];
	if (firstarg.compare("add") == 0){
		cout << "Doing add" << endl;
		string date = argv[2];
		string task = argv[3];
		cout <<"date "<<date<<" task "<<task<<endl;
		myList.add(date, task);
	}else if (firstarg.compare("remove") == 0){
		cout << "Doing remove" << endl;
		string task = argv[2];
		myList.remove(task);
	}else if(firstarg.compare("printList") == 0){
		cout << "Doing printlist" << endl;
		myList.printTodoList();
	}else if(firstarg.compare("printDay") == 0){
		cout << "Doing printDay" << endl;
		string day = argv[2];
		myList.printDaysTasks(day);
	}else{
		cout << "TODO requires more positional arguments:" << endl;
		cout << left << setw(25) << "\tadd [_duedate] \"_task\"" << "add task to list" << endl;
		cout << left << setw(25) << "\tremove \"_task\"" << "remove specified task" << endl;
		cout << left << setw(25) << "\tprintlist" << "prints todo list" << endl;
		cout << left << setw(25) << "\tprintday [day]" << "print tasks due on [day]" << endl;
		return 1;
	}
	//cout<<"darn double delete" << endl;
	//myList.~TodoList();
	//cout << "end of program" << endl;
}