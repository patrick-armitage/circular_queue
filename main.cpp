#include <iostream>
#include <string>
#include "Circularqueue.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

string getSelection();

int main() {
    cout << "Welcome to CircularQueue Demo.  Please select an option:" << endl;
    Circularqueue *cQ = new Circularqueue;
    string sel = getSelection();
    cin.ignore();
    int value;
    while (sel != "x)") {
        if (sel == "a)") {
            cin >> value;
            cQ->addBack(value);
            cout << endl;
        } else if (sel == "b)") {
            value = cQ->getFront();
            cout << "Front value is " << value << endl << endl;
        } else if (sel == "c)") {
            value = cQ->removeFront();
            if (value > -1) {
                cout << "Removed " << value << " from the CircularQueue!" << endl << endl;
            } else {
                cout << "CircularQueue is empty!  Current value is " << value << endl << endl;
            }
        } else if (sel == "d)") {
            cQ->printNodes();
            cout << endl;
        } else {
            cout << "Not a valid entry.  Please try again." << endl << endl;
        }

        sel = getSelection();
    }

    return 0;
}

string getSelection() {
    string selection;
    cout << "a) Enter a value" << endl;
    cout << "b) Display first value" << endl;
    cout << "c) Remove a value" << endl;
    cout << "d) Display the queue contents" << endl;
    cout << "x) Exit" << endl;
    cin >> selection;

    return selection;
}
