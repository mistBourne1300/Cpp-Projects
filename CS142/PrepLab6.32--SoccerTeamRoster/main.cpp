// 1 1 2 2 3 3 4 4 5 5 a 6 6 o d 4 o u 6 7 o r 3 q

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void OutputRoster(const vector<int>& jerseys, const vector<int>& ratings);
void AddPlayer(vector<int>& jerseys, vector<int>& ratings);
void ExterminatePlayer(vector<int>& jerseys, vector<int>& ratings);
void UpdatePlayerRating(vector<int>& jerseys, vector<int>& ratings);
void OutputPlayerAboveRating(vector<int>& jerseys, vector<int>& ratings);

int main() {
    const string MENU = "MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit";
    char userChoice = ' ';

    vector<int> jerseyNums;
    vector<int> playerRatings;

    for(int i = 0; i < 5; i++){
        int tempJersey = 0, tempRating = 0;
        cout << "Enter player " << i+1 << "'s jersey number: ";
        cin >> tempJersey;
        cout << endl << "Enter player " << i+1 << "'s rating: ";
        cin >> tempRating;
        cout << endl;
        jerseyNums.push_back(tempJersey);
        playerRatings.push_back(tempRating);
    }

    OutputRoster(jerseyNums, playerRatings);


    do{
        cout << MENU << endl << endl;
        cout << "Choose an option: ";
        cin >> userChoice;
        cout << endl;

        if(userChoice == 'a'){
            AddPlayer(jerseyNums, playerRatings);
        }
        else if(userChoice == 'd'){
            ExterminatePlayer(jerseyNums, playerRatings);
        }
        else if(userChoice == 'u'){
            UpdatePlayerRating(jerseyNums, playerRatings);
        }
        else if(userChoice == 'r'){
            OutputPlayerAboveRating(jerseyNums, playerRatings);
        }
        else if(userChoice == 'o'){
            OutputRoster(jerseyNums, playerRatings);
        }
        else if(userChoice == 'q'){

        }
        else {
            cout << "That was not a valid choice" << endl;
        }


    }while(userChoice != 'q');
    return 0;
}

void OutputRoster(const vector<int>& jerseys, const vector<int>& ratings){
    cout << "ROSTER" << endl;
    for(int i = 0; i < jerseys.size(); i++){
        cout << "Player " << i+1 << " -- ";
        cout << "Jersey number: " << jerseys.at(i) << ", ";
        cout << "Rating: " << ratings.at(i) << endl;
    }
    cout << endl;
}

void AddPlayer(vector<int>& jerseys, vector<int>& ratings){
    int tempJersey = 0, tempRating = 0;
    cout << "Enter another player's jersey number: ";
    cin >> tempJersey;
    cout << endl << "Enter another player's rating: ";
    cin >> tempRating;
    cout << endl;

    jerseys.push_back(tempJersey);
    ratings.push_back(tempRating);
}

void ExterminatePlayer(vector<int>& jerseys, vector<int>& ratings){
    int jerseyToExterminate;
    cout << "Enter a jersey number: ";
    cin >> jerseyToExterminate;
    cout << endl;

    int index = 0;
    for(index; index < jerseys.size(); index++){
        if(jerseyToExterminate == jerseys.at(index)){
            break;
        }
    }
    jerseys.erase(jerseys.begin() + index);
    ratings.erase(ratings.begin() + index);

}

void UpdatePlayerRating(vector<int>& jerseys, vector<int>& ratings){
    int jerseyNum, newRating;
    cout << "Enter a jersey number: ";
    cin >> jerseyNum;
    cout << endl;

    cout << "Enter a new rating for player: ";
    cin >> newRating;
    cout << endl;

    for(int i = 0; i < jerseys.size(); i++){
        if(jerseys.at(i) == jerseyNum){
            ratings.at(i) = newRating;
        }
    }
}

void OutputPlayerAboveRating(vector<int>& jerseys, vector<int>& ratings){
    int ratingToOutput;
    cout << "Enter a rating: ";
    cin >> ratingToOutput;
    cout << endl;

    cout << "ABOVE" << ratingToOutput << endl;
    for(int i = 0; i < jerseys.size(); i++){
        if(ratings.at(i) > ratingToOutput) {
            cout << "Player " << i + 1 << " -- ";
            cout << "Jersey number: " << jerseys.at(i) << ", ";
            cout << "Rating: " << ratings.at(i) << endl;
        }
    }
    cout << endl;
}