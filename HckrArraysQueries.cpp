#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// Sample Input :
// 2 2 -> Number of arrays, then number of queries
// 3 1 5 4 -> First array of four elements
// 5 1 2 8 9 3 -> Second array of six elements
// 0 1 -> First query on array 0 at element 1
// 1 3 -> Second query on array 1 at element 3

// Sample Output :
// 1 -> element 1 in array 0, from first query
// 8 -> element 3 in array 1, from second query

int main() {

    // Take in num of arrays and num of queries
    int n, q;
    cin >> n >> q;
    cin.ignore(1); // If you don't do this it won't work.

    // Take in arrays and their elements
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        istringstream iss(str);
        int is;
        while (iss >> is) {
            a[i].push_back(is);
        }
    }

    // Take in queries
    vector<vector<int>> query(q);
    for (int u = 0; u < q; u++) {
        query[u] = vector<int>(2);
        cin >> query[u][0];
        cin >> query[u][1];
    }

    // Perform queries
    for (int v = 0; v < q; v++) {
        printf("%d\n", a[query[v][0]][query[v][1]]);
    }

    return 0;
}