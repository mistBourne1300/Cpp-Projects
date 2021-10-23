#include <queue>
#include <iostream>
#include <fstream>
using namespace std;

void print_queue(queue<int> Q){
    while(!Q.empty()){
        if(Q.size() > 1){
            cout << Q.front() << ",";
            Q.pop();
        }else{
            cout << Q.front() << endl;
            Q.pop();
        }
    }
    return;
}

double get_queue_average(queue<int> Q){
    int sum = 0;
    int size = Q.size();
    while(!Q.empty()){
        sum += Q.front();
        Q.pop();
    }
    return sum/size;
}

int main(int argc, char *argv[]){
    if(argc < 3){
        cout << "COVID requires more positional arguments:" << endl;
        cout << "./covid [filename] [days rolling]" << endl;
    }
    queue<int> rolling_average;
    ifstream inFS;
    inFS.open(argv[1]);
    if(!(inFS.is_open())){
        cout << "File not found" << endl;
        return 1;
    }
    int temp_input = 0;
    //cout << "argv[2]: " << argv[2] << " *argv[2]: " << *argv[2] << " (int)*argv[2]: " << (int)*argv[2] << endl;
    int num_days = *argv[2] - '0';
    cout << "Using Data from " << argv[1] << " with a " << num_days << " day rolling average" << endl;
    for(int i = 0; i < num_days && !(inFS.eof()); i++){
        inFS >> temp_input;
        rolling_average.push(temp_input);
    }
    //print_queue(rolling_average);
    double average = 0;
    while (!inFS.eof()){
        print_queue(rolling_average);
        average = get_queue_average(rolling_average);
        cout << "Average " << average << endl;
        rolling_average.pop();
        inFS >> temp_input;
        rolling_average.push(temp_input);
    }
    print_queue(rolling_average);
    average = get_queue_average(rolling_average);
    cout << "Average " << average << endl;
    
    return 0;

}