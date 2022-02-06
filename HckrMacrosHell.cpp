#define FUNCTION(m, c) void m(int& mval, int val) { mval = mval c val ? mval : val; }
#define INF (unsigned)!((int)0)
#define toStr(s) #s
#define io(vec) cin >> vec
#define foreach(vec, x) for (int x = 0; x < vec.size(); x++)

// This is absolute madness. Holy shit, who on earth uses macros like this, jesus christ.
// The foreach macro is not a for each at all, get baited sike.
// The io macro is impossible to understand at first
// The Function macro is just pure madness at this point. If I were in hell, it'd be my punishment to write code like this.

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) << ' ' << ans;
	return 0;
}