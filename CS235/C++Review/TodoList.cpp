#include "TodoList.h"

void TodoList::add(string _duedate, string _task){
	cout << "\nAdd Accessed" << endl;
	todoDates.push_back(_duedate);
	todoList.push_back(_task);
}

int TodoList::remove(string _task){
		cout << "\nRemove Accessed" << endl;
		int index = -1;
		for(int i = 0; i < todoList.size(); i++){
			if(_task.compare(todoList.at(i)) == 0){
				index = i;
				break;
			}
		}
		if(index > 0){
			cout << "\tremoving task no." << index << endl;
			todoList.erase(todoList.begin() + index);
			todoDates.erase(todoDates.begin() + index);
			cout << "\ttask removed" << endl;
		}else{
			cout << "no such task" << endl;
		}
		
		return 0;
}

void TodoList::printTodoList(){
		cout << "\nPrint Accessed" << endl;
		for(int i = 0; i<todoDates.size(); i++){
			cout << "\t" << todoList.at(i) << "\n\t\tdue: " << todoDates.at(i) << endl;
		}
}

void TodoList::printDaysTasks(string _date){
		cout << "\nPrint days Accessed" << endl;
		for(int i = 0; i < todoDates.size(); i++){
			if(todoDates.at(i).compare(_date) == 0){
				cout << "\t" << todoList.at(i) << "\n\t\tdue: " << todoDates.at(i) << endl;
			}
		}
}