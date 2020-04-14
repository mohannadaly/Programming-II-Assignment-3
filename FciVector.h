#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class FciVector {
public:
    FciVector();

    void push_back(T);

    void pop_back();

    void insert(T*, T);

    void erase(T*);

    void clear();

    T* begin();

    T& back();

    T& front();

    T& operator[](int x);

    int size() const;

    int capacity();

    bool empty();

    void choices();

private:
    T* arr; // dynamic array pointer
    int s; // vector size
    int cap; // vector capacity
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation/////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
FciVector<T>::FciVector() {
    s = 0; // initialize size
    cap = 1; // initialize capacity
    arr = new T[cap]; // create dyanmic array with size 1
}

template<class T>
void FciVector<T>::push_back(T element) {
    if (s == cap) { // if vector is full, double the capacity
        cap *= 2;
        T* newArr = new T[cap]; // temporary array with new capacity
        for (int i = 0; i < s; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr; // free previous memory before moving
        arr = newArr; // point to new memory
    }
    arr[s++] = element; // store the element
}

template<class T>
void FciVector<T>::pop_back() {
    s--; // decrement size counter
    T* newArr = nullptr; // temporary array
    if (s == cap / 2) { // if capacity can be reduced
        cap /= 2; // divide it by 2
        newArr = new T[cap]; // create array with new capacity
    }
    else newArr = new T[cap]; // otherwise create array with normal capacity
    for (int i = 0; i < s; i++) { // move elements from old array to new one
        newArr[i] = arr[i];
    }
    delete[] arr; // free previous memory before moving
    arr = newArr; // point to new memory
}

template<class T>
void FciVector<T>::insert(T* iterator, T element) {
    int index = iterator - arr; // extract index from provided pointer
    if (s == cap) push_back(arr[s - 1]); // add extra capcity if needed
    for (int i = s - 2; i >= index; i--) { // shift elements forwards
        arr[i + 1] = arr[i];
    }
    arr[index] = element; // store element
}

template<class T>
void FciVector<T>::erase(T* iterator) {
    int index = iterator - arr; // extract index from provided pointer
    for (int j = index; j < s - 1; j++) { // overwrite desired element
        arr[j] = arr[j + 1];
    }
    pop_back(); // shrink vector
}

template<class T>
void FciVector<T>::clear() {
    delete[] arr; // delete stored values
    arr = new T[1]; // create new array
    s = 0; // reset size
    cap = 1; // reset capacity
}

template<class T>
T* FciVector<T>::begin() {
    return arr; // return pointer to the array
}

template<class T>
T& FciVector<T>::back() {
    return arr[s - 1]; // return last element in the array
}

template<class T>
T& FciVector<T>::front() {
    return arr[0]; // return first element in the array
}

template<class T>
T& FciVector<T>::operator[](int x) {
    return arr[x]; // return element at index x in the array
}

template<class T>
int FciVector<T>::size() const {
    return s; // return array's size
}

template<class T>
int FciVector<T>::capacity() {
    return cap; // return array's capacity
}

template<class T>
bool FciVector<T>::empty() {
    return s == 0; // return true if vector is empty, false otherwise
}

template<class T>
void FciVector<T>::choices() {
    int choice = 0;
print2:
    cout << "1. Add element.\n" // print second menu
        "2. Remove last element.\n"
        "3. Insert element at certain position.\n"
        "4. Erase element from a certain position.\n"
        "5. Clear.\n"
        "6. Display first element.\n"
        "7. Display last element.\n"
        "8. Display element at certain position.\n"
        "9. Display vector size.\n"
        "10. Display vector capacity.\n"
        "11. Is empty?" << endl;
menu2:
    while (!(cin >> choice) || !(choice >= 1 && choice <= 11)) { // check for out-of-bounds or invalid data type input
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid choice, please try again" << endl;
    }
    switch (choice) {
    case 1: {
        int count = 0;
        cout << "How many elements would you like to add: ";
        while (!(cin >> count) || count < 0) { // check for invalid data type input
            cin.clear(); // clear stream
            cin.ignore(9999, '\n'); // ignore characters in the stream
            cout << "Invalid number of elements, please try again" << endl;
        }
        cin.ignore();
        for (int i = 0; i < count; i++) {
            T element;
            cout << "Element " << i + 1 << ':' << endl;
            while (!(cin >> element)) { // check for invalid data type input
                cin.clear(); // clear stream
                cin.ignore(9999, '\n'); // ignore characters in the stream
                cout << "Invalid input, please try again" << endl;
            }
            push_back(element); // add element in the vector
        }
        cout << count << " elements added" << endl;
        break;
    }
    case 2: {
        if (s == 0) cout << "Vector is already empty" << endl; // if vector is already empty
        else {
            cout << "Last element removed" << endl;
            pop_back(); // shrink the vector
        }
        break;
    }
    case 3: {
        cout << "Enter the index at which you would like to insert: ";
        int i = 0;
        while (!(cin >> i) || i > size() || i < 0) { // check for invalid index or data type input
            cin.clear(); // clear stream
            cin.ignore(9999, '\n'); // ignore characters in the stream
            cout << "Invalid index, please try again" << endl;
        }
        int count = 0;
        cout << "How many elements would you like to add: ";
        while (!(cin >> count) || count < 0) { // check for invalid count or data type input
            cin.clear(); // clear stream
            cin.ignore(9999, '\n'); // ignore characters in the stream
            cout << "Invalid number of elements, please try again" << endl;
        }
        cin.ignore();
        for (int j = 0; j < count; j++) {
            T element;
            cout << "Element " << i + 1 << ':' << endl;
            while (!(cin >> element)) { // check for invalid data type input
                cin.clear(); // clear stream
                cin.ignore(9999, '\n'); // ignore characters in the stream
                cout << "Invalid input, please try again" << endl;
            }
            insert(begin() + i + j, element); // insert element at index i
        }
        cout << count << " elements added" << endl;
        break;
    }
    case 4: {
        if (s == 0) cout << "Vector is already empty" << endl; // if vector is already empty
        else {
            cout << "Enter the index at which you would like to erase: ";
            int i = 0;
            while (!(cin >> i) || i > size() - 1 || i < 0) { // check for invalid index or data type input
                cin.clear(); // clear stream
                cin.ignore(9999, '\n'); // ignore characters in the stream
                cout << "Invalid index, please try again" << endl;
            }
            cout << "Element erased" << endl;
            erase(begin() + i); // erase element at index i
        }
        break;
    }
    case 5: {
        cout << "Vector cleared" << endl;
        clear(); // clear the array
        break;
    }
    case 6: {
        if (s == 0) cout << "Vector is empty" << endl; // if vector is empty
        else {
            cout << "First element: " << endl;
            cout << front() << endl; // print first element in the array
        }
        break;
    }
    case 7: {
        if (s == 0) cout << "Vector is empty" << endl; // if vector is empty
        else {
            cout << "Last element: " << endl;
            cout << back() << endl; // print last element in the array
        }
        break;
    }
    case 8: {
        if (s == 0) cout << "Vector is empty" << endl; // if vector is empty
        else {
            cout << "Enter the index of your element: ";
            int i = 0;
            while (!(cin >> i) || i > size() - 1 || size() < 0) { // check for invalid index or data type input
                cin.clear(); // clear stream
                cin.ignore(9999, '\n'); // ignore characters in the stream
                cout << "Invalid index, please try again" << endl;
            }
            cout << "Element " << i << ":" << endl;
            cout << (*this)[i] << endl; // print element at index i
        }
        break;
    }
    case 9: {
        cout << "Vector Size: " << size() << endl; // print vector's size
        break;
    }
    case 10: {
        cout << "Vector Capacity: " << capacity() << endl; // print vector's capacity
        break;
    }
    case 11: {
        cout << ((empty()) ? "Vector is empty" : "Vector is not empty") << endl; // print whether vector is empty
        break;
    }
    default: {
        cout << "Invalid choice, please try again." << endl; // if user choose anything not within 1-11
        goto menu2; // ask for input again
    }
    }
    cout << "Would you like to perform other operations? (Y/N)" << endl; // check for desire to do other operations
    char retry = ' ';
    while (!(cin >> retry) || (retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n')) { // check for wrong data type input
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid choice, please try again" << endl;
    }
    if (retry == 'Y' || retry == 'y') goto print2; // print second menu
}