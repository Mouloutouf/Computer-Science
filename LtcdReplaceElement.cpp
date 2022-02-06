// Replace all elements of the list with the maximum value found to the left of each element
// Ex : [17,18,5,4,6,1] becomes -> [18,6,6,6,1,-1]
// And replace the last element of the list with -1

class Solution1 {
    // Slow solution
    // Loop the list forward, and use a second Loop to check for the maximum value
    // This is very inefficient
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i){
            // Replace the last element of the list with -1
            if (i == arr.size() - 1){
                arr[i] = -1;
                continue;
            }
            // Loop to find maximum value
            int g = 0;
            for (int j = i + 1; j < arr.size(); ++j){
                if (arr[j] > g)
                    g = arr[j];
            }
            arr[i] = g;
        }
        return arr;
    }
};

class Solution2 {
    // Fast Solution
    // Loop the list backwards
    // At each step, save the current value, replace the current value with max, then replace max with the saved value if it is superior to max
    // Smart as hell, since you can replace the values and look for the maximum value at the same time
    // Since we look for the max value to the right of each element, then by progressing towards the left, we can make sure the max value increases as we go left, and be safe to replace elements
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        int a;
        for (int i = arr.size() - 1; i >= 0; --i){
            a = arr[i];
            arr[i] = max;
            max = std::max(max, a);
        }
        return arr;
    }
};
