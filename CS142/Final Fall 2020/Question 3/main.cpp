#include <iostream>
using namespace std;

//Define your class here

class Door{
    bool isOpen;
    bool isLocked;
public:
    Door();
    void OpenDoor();
    void CloseDoor();
    void LockDoor();
    void UnlockDoor();
};

void Door::OpenDoor(){
    if(isOpen){
        cout << "The door is already open." << endl;
        return;
    }
    else if(isLocked){
        cout << "Sorry, the door is locked." << endl;
        return;
    }
    isOpen = true;
}

void Door::CloseDoor() {
    if(!isOpen){
        cout << "The door is already shut." << endl;
        return;
    }
    isOpen = false;
}

void Door::LockDoor() {
    if(isOpen){
        cout << "Sorry, the door is open." << endl;
        return;
    }
    else if(isLocked){
        cout << "The door is already locked." << endl;
        return;
    }
    isLocked = true;
}

void Door::UnlockDoor() {
    if(isOpen){
        cout << "Sorry, the door is open." << endl;
        return;
    }
    else if(!isLocked){
        cout << "The door is already unlocked." << endl;
        return;
    }
    isLocked = false;
}

Door::Door() {
    isOpen = false;
    isLocked = true;
}



//Do not edit below this line-----------------------------------------------------------------

int main() {
    Door pantryDoor;
    Door frontDoor;


    frontDoor.LockDoor();
    frontDoor.UnlockDoor();
    frontDoor.UnlockDoor();
    frontDoor.OpenDoor();
    frontDoor.LockDoor();
    frontDoor.UnlockDoor();
    frontDoor.CloseDoor();
    frontDoor.LockDoor();
    frontDoor.LockDoor();
    pantryDoor.OpenDoor();
    pantryDoor.UnlockDoor();
    pantryDoor.OpenDoor();
    pantryDoor.OpenDoor();
    frontDoor.CloseDoor();
    pantryDoor.CloseDoor();
    pantryDoor.CloseDoor();
    pantryDoor.LockDoor();
    pantryDoor.OpenDoor();

    return 0;
}
