#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Creating very specific implementations for each template type, makes the code go faster

template <typename T>
class AddElements {
    T element;
public:
    AddElements(T _element) { element = _element; }
    // T add(T _newElement) { return element + _newElement; } -> not specific enough -> not fast enough
};

template <>
class AddElements<string>{
    string element;
public:
    AddElements(string _element) { element = _element; }
    string concatenate(string _newElement) { return element + _newElement; }
};

template <>
class AddElements<int>{
    int element;
public:
    AddElements(int _element) { element = _element; }
    int add(int _newElement) { return element + _newElement; }
};

template <>
class AddElements<double>{
    double element;
public:
    AddElements(double _element) { element = _element; }
    double add(double _newElement) { return element + _newElement; }
};

int main () {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1,element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}