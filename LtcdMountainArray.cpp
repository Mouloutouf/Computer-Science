#include <vector>
using namespace std;

class Solution1 {
    // RandomIQ solution
public:
    bool validMountainArray(vector<int>& arr) {
        // Mountain Array cannot have less than 3 elements
        if (arr.size() < 3)
            return false;
        // Status of the Mountain Array. 0 is ascending, 1 is descending
        int s = 0;
        for (int i = 1; i < arr.size(); ++i){
            // Ascending
            if (s == 0){
                if (arr[i] > arr[i - 1]){
                    continue;
                }
                else if (arr[i] == arr[i - 1]){
                    // Moutain Array cannot have two successive equal values
                    return false;
                }
                else{
                    if (i == 1)
                        // the Mountain Array does not ascend
                        return false;
                    // Start descending
                    s++;
                }
            }
            //Descending
            else{
                if (arr[i] < arr[i - 1]){
                    continue;
                }
                else if (arr[i] == arr[i - 1]){
                    // Moutain Array cannot have two successive equal values
                    return false;
                }
                else{
                    // Mountain Array cannot re-ascend
                    return false;
                }
            }
        }
        if (s == 0)
            // the Mountain Array does not descend
            return false;
        return true;
    }
};

class Solution2 {
    // 300IQ solution
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        // Mountain Array cannot have less than 3 elements
        if (size < 3)
            return false;
        int i=0;
        // As long as the array is ascending, increase i
        while (i+1 < size && arr[i] < arr[i+1]){
            i++;
        }
        // If the array stops ascending at the first value, or if it stops ascending at the last value (e.g. it never ascended, or it never descended)
        if(i==0 || i == size-1){
            return false;
        }
        // As long as the array is now descending, keep increasing i
        while(i+1 < size && arr[i] > arr[i+1]){
            i++;
        }
        // If i is the size of the array, the array is a Mountain Array
        return i == size-1;
    }

    // Even faster
    bool validMountainArray2(vector<int>& arr)
    {
        //ascending loop
        int i=0;
        if(arr.size()<=2)
        {
            return false;
        }
        while(i < arr.size() && arr[i] < arr[i+1])
        {
            i++;
        }
        if( i == 0 || i == arr.size() - 1 )
        {
            return false;
        }
        while(i+1<arr.size() && arr[i] > arr[i+1])
        {
        i++;
        }
        return i == arr.size()-1;
    }
};
