#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& elements, int size) {
    if (elements.size() <= 1)
        return;
    for (int i = 1; i < size; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (elements[i] < elements[j]) {
                int t = elements[j];
                elements[j] = elements[i];
                elements[i] = t;
            }
        }
    }
}

main() {
    int n = 6;
    vector<int> a = {1, 4, 6, 2, 7, 9};
    InsertionSort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cin.get();
}