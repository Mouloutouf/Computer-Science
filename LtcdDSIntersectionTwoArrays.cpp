#include <vector>
#include <map>
using namespace std;

// This Exercice is an Absolute Piece of Shit, the Description of the Problem just did not point towards the Resolution of the Problem, at All.
// It was incredibly Unclear and Vague with Few Examples what 'Intersection' even meant. Only when I looked for the Solution did I actually
// Understand the Damn Exercice.
// Essentially, the 'Intersection' just means Compare the Two Arrays and return the Numbers that are Present in both.
// So what you do is take the Biggest Array, put all Numbers into a Map, so you know which Numbers there are and how Many times they Appear in the Array
// Then you take the Smallest Array and compare the Numbers in this Array to the Numbers present in the Map. Then Add it to the Result if they are Present.
// That's fucking it. Jesus, you don't even need a Map to do this. You can just Sort both of the Arrays and Compare them too, that's Another Solution.
// Anyway this was quite a Waste of Time, for Something that is not Complicated at All to Do.

class WIPSolution { // Does not Work
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &biggest = nums1.size() > nums2.size() ? nums1 : nums2;
        vector<int> &smallest = nums1.size() > nums2.size() ? nums2 : nums1;
        int i = 0, j = 0;
        vector<int> intersect;
        while (j < smallest.size()){
            if (biggest[i] == smallest[j]){
                intersect.push_back(biggest[i]);
                ++j;
            }
            ++i;
            if (i >= biggest.size()){
                ++j;
                i = 0;
            }
        }
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &b = nums1.size() > nums2.size() ? nums1 : nums2;
        vector<int> &s = nums1.size() > nums2.size() ? nums2 : nums1;
        map<int, int> o;
        vector<int> r;
        for (int i = 0; i < b.size(); ++i){
            o[b[i]]++;
        }
        for (int j = 0; j < s.size(); ++j){
            if (o[s[j]] != 0){
                r.push_back(s[j]);
                o[s[j]]--;
            }
        }
        return r;
    }
};