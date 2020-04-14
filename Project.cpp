/*
Name: Mohanad Ayman Aly
ID: 20180296
Group: G5
*/
#include "Student.h"

class xstring { // class to store string
private:
    string s;
public:
    friend istream& operator>>(istream& in, xstring& str) { // istream operator overload
        getline(in, str.s);
        return in;
    }

    friend ostream& operator<<(ostream& out, xstring& str) { // ostream operator overload
        out << str.s;
        return out;
    }

    xstring operator=(const xstring& str) { // assignment operator overload
        s = str.s;
        return *this; // dereference pointer to this object to allow chaining
    }
};

int main() {
    int choice = 0, exit = 0; // user's choice, flag to exit program
print1:
    cout << "Insert type of vector you would like to create:\n" // print main menu
        "1. list of integer\n"
        "2. list of character\n"
        "3. list of string\n"
        "4. list of float\n"
        "5. list of students\n"
        "6. Exit" << endl;
menu1:
    while (!(cin >> choice) && choice >= 1 && choice <= 6) { // check for invalid choice or data type
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore leftover characters
        cout << "Invalid choice, please try again" << endl;
    }
    switch (choice) { // switch to create vector based on user's choice
    case 1: {
        cout << "List of integers created successfully" << endl;
        FciVector<int> temp;
        temp.choices();
        break;
    }
    case 2: {
        cout << "List of characters created successfully" << endl;
        FciVector<char> temp;
        temp.choices();
        break;
    }
    case 3: {
        cout << "List of strings created successfully" << endl;
        FciVector<xstring> temp;
        temp.choices();
        break;
    }
    case 4: {
        cout << "List of floats created successfully" << endl;
        FciVector<float> temp;
        temp.choices();
        break;
    }
    case 5: {
        cout << "List of students created successfully" << endl;
        FciVector<Student> temp;
        temp.choices();
        break;
    }
    case 6: {
        cout << "Exiting..." << endl;
        exit = 1;
        break;
    }
    default: { // if user enters anything not within 1-6
        cout << "Invalid choice, please try again" << endl;
        goto menu1; // ask for input again
    }
    }
    if (exit == 0) goto print1; // print main menu again
    return 0;
}