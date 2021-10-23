#include <iostream>
#include <vector>
using namespace std;

double TotalWeight(vector<double> weights);
double AverageWeight(vector<double> weights);
double MaxWeight(vector<double> weights);

int main() {
    vector<double> peoplesWeights;
    for(int i = 0; i < 5; i++){
        double temp = 0.0;
        cout << "Enter weight " << i+1 << ": ";
        cin >> temp;
        cout << endl;
        peoplesWeights.push_back(temp);
    }

    cout << "You entered: ";
    for(int i = 0; i < peoplesWeights.size(); i++){
        cout << peoplesWeights.at(i) << " ";
    }
    cout << endl;

    cout << "Total weight: " << TotalWeight(peoplesWeights) << endl;
    cout << "Average weight: " << AverageWeight(peoplesWeights) << endl;
    cout << "Max weight: " << MaxWeight(peoplesWeights) << endl;

    return 0;
}


double TotalWeight(vector<double> weights){
    double sum = 0;
    for(int i = 0; i < weights.size(); i++){
        sum+=weights.at(i);
    }
    return sum;
}

double AverageWeight(vector<double> weights){
    double sum = TotalWeight(weights);
    return sum / weights.size();
}

double MaxWeight(vector<double> weights){
    double maxWeight = weights.at(0);
    for(int i = 0; i < weights.size(); i++){
        if(maxWeight < weights.at(i)){
            maxWeight = weights.at(i);
        }
    }
    return maxWeight;
}