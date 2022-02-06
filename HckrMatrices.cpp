#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
public:
   Matrix() {}
   Matrix(vector<vector<int>> v) { a = v; }
   vector<vector<int>> a;
   Matrix operator + (Matrix& other) {
      auto b = vector<vector<int>>(a.size());
      for (unsigned int i = 0; i < a.size(); i++) {
         b[i] = vector<int>(a[i].size());
         for (unsigned int u = 0; u < a[i].size(); u++) {
            b[i][u] = a[i][u] + other.a[i][u];
         }
      }
      return Matrix(b);
   }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}