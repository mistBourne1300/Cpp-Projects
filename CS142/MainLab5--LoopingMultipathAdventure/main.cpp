#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

char PromptUserForInput(string prompt, string validInputs);

void ConsequencesForNoncompliance();

string GetChoiceConsequences(char choice1, char choice2, char choice3, bool isSafe);



int main() {
    srand(time(0));
    char userInput;
    char choice1 = '0';
    char choice2 = '0';
    char choice3 = '0';
    char goOn = 'y';
    int testSubject = 0;
    bool safeAndSound;

    while (goOn == 'y') {
        safeAndSound = false;


        cout << "Welcome, 00" << testSubject << "." << endl
             << "You are stuck in a labrynth by Dr. Evil. " <<
             "The only way to escape is to find the exit. Do you:" << endl;
        cout << "a) Walk right" << endl
             << "b) Walk left" << endl
             << "c) Walk straight" << endl;
        userInput = PromptUserForInput("Pick your poison (enter a, b, or c):", "abc?");

        if (userInput == 'a') {
            //walk right
            choice1 = 'a';


            cout << "You are now in an aviary. You see three types of birds: "
                 << "a giant eagle with razor-sharp claws, a flock of pigeons innocently pecking at the ground, "
                 << "and a colorful parrot. Do you:" << endl;

            cout << "a) Approach the eagle" << endl
                 << "b) Approach the pigeons" << endl
                 << "c) Approach the parrot" << endl;
            userInput = PromptUserForInput("Select your fowl (enter a, b, or c):", "abc");

            while (userInput == 'b') {
                cout << "The pidgeons are pidgeons. They are easily startled and fly away" << endl;
                cout << "a) Approach the eagle" << endl
                     << "b) Approach the pigeons" << endl
                     << "c) Approach the parrot" << endl;
                userInput = PromptUserForInput("Select your fowl (enter a, b, or c):", "abc");
            }

            //since the user can't have chosen 'b', only 'a' and 'c' are left.
            if (userInput == 'a') {
                // approach the eagle
                choice2 = 'a';
                cout << "The giant eagle eats you as a tasty snack. You are not Gandalf. Goodbye." << endl;

            } else if (userInput == 'c') {
                //approach the parrot
                choice2 = 'c';
                cout << "The parrot is able to talk. You ask if there is any way out. "
                     << "It turns to the eagle, convinces it to give you a ride, and you "
                     << "hop on the eagle's back." << endl << "You fly away, safe and happy." << endl;
                safeAndSound = true;
            } else {
                ConsequencesForNoncompliance();
            }


        } else if (userInput == 'b') {
            //walk left
            choice1 = 'b';


            cout << "You fall into a whirlpool. Do you:" << endl;
            cout << "a) Try to swim out" << endl
                 << "b) Swim with the current" << endl;
            userInput = PromptUserForInput("Choose your preference (enter a or b):", "ab");

            if (userInput == 'a') {
                choice2 = 'a';
                cout << "You cannot fight the current, and you run out of strength. You die.";
                choice1 = 'b';


            } else if (userInput == 'b') {
                choice2 = 'b';

                cout << "You get flushed down into the sewer. "
                     << "After a few hours crawling in the dark, you see light ahead." << endl
                     << "Congratulations. You are free. But you definitely need a shower.";
                safeAndSound = true;
            } else {
                ConsequencesForNoncompliance();
            }


        } else if (userInput == 'c') {
            //walk straight
            choice1 = 'c';


            cout << "You are now in a large circular pit halfway filled with sand. Do you:" << endl;
            cout << "a) Walk out to the center" << endl
                 << "b) Turn around" << endl;
            userInput = PromptUserForInput(
                    "Reflect on your choices. Everything in your life has led to this moment. (enter a or b):",
                    "ab");

            if (userInput == 'a') {
                choice2 = 'a';


                cout << "A  Sarlacc appears beneath you and bites your leg off. "
                     << "You taste so bad that he flings you out of the sand pit. "
                     << "Congratulations! You--well, most of you--has escaped the labyrinth!" << endl;
                safeAndSound = true;
            } else if (userInput == 'b') {
                choice2 = 'b';


                cout << "You are back in the hallway, but a pit of spikes has appeared. Do you:" << endl;
                cout << "a) Try to jump the spikes" << endl
                     << "b) Crawl down in to the spikes" << endl;
                userInput = PromptUserForInput(
                        "You have a jump bonus. You REALLY want to try to jump the spikes. (enter a or b):", "ab");

                if (userInput == 'a') {
                    choice3 = 'a';
                    cout << "Your jump roll fails, and you die.";
                } else if (userInput == 'b') {
                    choice3 = 'b';
                    cout << "You discover that there is a service hatch beneath the spikes. "
                         << "Congratulations! You escaped!" << endl;
                    safeAndSound = true;
                } else {
                    ConsequencesForNoncompliance();
                }


            } else {
                ConsequencesForNoncompliance();
            }


        } else if (userInput == '?') {
            choice1 = '?';
            int intPassword = rand() % 10;

            char password = '0' + intPassword;

            cout << "Congratulations. You have found my easter egg. "
                 << "You must type in the one-digit password to open the door behind you to escape."
                 << endl << "You have " << (intPassword+1) << " chances.\n" << endl;
            //cout << endl << password << endl << endl;

            for (int i = 0; i<(intPassword + 1); ++i){
                cout << "ATTEMPT " << i+1 << endl;
                char userAttempt = PromptUserForInput("Enter your attempt (0-9):", "0123456789");
                if (userAttempt == password){
                    cout << "Password accepted." << endl;
                    safeAndSound = true;
                    i = intPassword + 1;
                }else {
                    cout << "Try again\n\n" << endl;
                }
            }
            if(!safeAndSound){
                ConsequencesForNoncompliance();
            }



        } else {
            ConsequencesForNoncompliance();
        }

        if (safeAndSound) {
            cout << endl << endl << endl << "With one last look at the prison from which you have escaped, you "
                 << GetChoiceConsequences(choice1, choice2, choice3, safeAndSound) << "\naway in slow motion, "
                 << "very dramatically placing shades over your eyes as the labrynth explodes behind you." << endl
                 << "(•_•) ( •_•)>⌐■-■ (⌐■_■)" << endl;
            cout << "\nWell done, 00" << testSubject << endl;
            ++testSubject;
        } else {
            cout << endl << endl << endl << "With your last " << GetChoiceConsequences(choice1, choice2, choice3,
                                                                                       safeAndSound)
                 << " of consciousness, you hear Dr. Evil over the PA system: "
                 << endl << "\"Test subject 00" << testSubject << ": failed.\"" << endl;
            ++testSubject;
            cout << "\"Bring in test subject 00"<< testSubject<< ".\""
                 << endl << "\\_(x_x)_/" << endl;
        }

        goOn = PromptUserForInput("\n\n\nWould you like to try again? (Enter 'y' or 'n'):", "yn");
    }


    return 0;
}


string GetChoiceConsequences(char choice1, char choice2, char choice3, bool isSafe) {
    if (choice1 == 'a'){
        //took the aviary. the only way to win is to choose 'c'.
        if (choice2 == 'a'){
            //took the eagle
            return "shred";
        }else if (choice2 == 'c'){
            //took the parrot and won
            return "fly";
        }else {
            return "wisp";
        }




    }else if (choice1 == 'b') {
        //took the whirlpool. the only way to win is to choose 'b'
        if (choice2 == 'a'){
            //died in the whirlpool
            return "bubble";
        }else if (choice2 == 'b'){
            //won in the whirlpool
            return "splash";
        }else {
            //died from nerotoxin
            return "wisp";
        }




    }else if (choice1 == 'c') {
        //took the sand pit
        if (choice2 == 'a'){
            //took the Sarlacc
            return "limp";
        }else if(choice2 == 'b'){
            // turned around. only way to win is to choose 'b'
            if (choice3 == 'a'){
                //died on the spikes
                return "spike";
            }else if (choice3 == 'b'){
                //escaped through the service hatch
                return "sprint";
            }else {
                //died from nerotoxin
                return "wisp";
            }
        }else {
            //died from neurotoxin
            return "wisp";
        }






    }else if (choice1 == '?') {
        //took the Easter egg
        if(isSafe){
            //succeeded in password attempts
            return "ride the Easter Bunny";
        }else {
            //failed password attempts
            return "wisp";
        }





    }else {
        //died from neurotoxin
        return "wisp";
    }
}




char PromptUserForInput(string prompt, string validInputs){
    char input;

    cout << prompt;
    cin >> input;
    while (validInputs.find(input) == string::npos){
        cout << "That is not a valid input. Please enter a valid input." << endl << prompt;
        cin >> input;
        cout << endl;
    }
    cout << endl;

    return input;
}

void ConsequencesForNoncompliance(){
    const string NONCOMPLIANCE_MESSAGE = "ಠ_ಠ\nI'm sorry. Dr. Evil has noticed what you are doing and is now filling the labrynth with a neurotoxin. Goodbye.";
    cout << NONCOMPLIANCE_MESSAGE;
}

