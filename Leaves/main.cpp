#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <ios>
using namespace std;

int main() {
    srand(time(0));
    int MIN_TREES = 4;
    int MAX_TREES = 20;
    int MIN_BRANCHES_PER_TREE = 30;
    int MAX_BRANCHES_PER_TREE = 100;
    int MIN_LEAVES_PER_BRANCH = 50;
    int MAX_LEAVES_PER_BRANCH = 200;

    int numLeavesTotal = 0;
    int numBranchesTotal = 0;
    int numTreesTotal = 0;

    cout << "Welcome to the trees/branches/leaves counter!" << endl;
    int numTrees = rand() % (MAX_TREES - MIN_TREES +1) + MIN_TREES;
    cout << "There are " << numTrees << " trees in the forest." << endl;
    for(int i = 0; i < numTrees; i++){
        int numBranches = rand() % (MAX_BRANCHES_PER_TREE - MIN_BRANCHES_PER_TREE + 1) + MIN_BRANCHES_PER_TREE;
        cout << "\t" << "Tree #" << i << " has " << numBranches << " branches" <<  endl;
        for(int j = 0; j < numBranches; j++){
            int numLeaves = rand() % (MAX_LEAVES_PER_BRANCH - MIN_LEAVES_PER_BRANCH + 1) + MIN_LEAVES_PER_BRANCH;
            cout << "\t\t" << "Branch #" << j << " has " << numLeaves << " leaves" << endl;
            for(int k = 0; k < numLeaves; k++){
                numLeavesTotal++;
            }
            numBranchesTotal++;
        }
        numTreesTotal++;
    }
    cout << setw(20) << setfill('*') << "DONE" << endl;
    cout << endl;

    cout << "The forest has " << numTreesTotal << " trees total." << endl;
    cout << "The forest has " << numBranchesTotal << " branches total." << endl;
    cout << "The forest has " << numLeavesTotal << " leaves total." << endl;
}
