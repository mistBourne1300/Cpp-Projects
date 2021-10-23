#include <iostream>
#include <string>
using namespace std;
/*
i becomes !
a becomes @
l (lowercase "L") becomes 1
B becomes 8
E becomes 3
m becomes M
s becomes $
 */

int main() {

    string password;
    cin >>password;
    for (int i = 0; i < password.size(); i++){
        if(password[i] == 'i'){
            password[i] = '!';
        }else if(password[i] == 'a'){
            password[i] = '@';
        }else if(password[i] == 'l'){
            password[i] = '1';
        }else if(password[i] == 'B'){
            password[i] = '8';
        }else if(password[i] == 'E'){
            password[i] = '3';
        }else if(password[i] == 'm'){
            password[i] = 'M';
        }else if(password[i] == 's'){
            password[i] = '$';
        }
    }

    password += "z^w";

    cout << password << endl;

    return 0;
}
