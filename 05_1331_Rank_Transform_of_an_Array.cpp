#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Copy original array
        vector<int> s = arr;

        // Sort the copied array
        sort(s.begin(), s.end());

        // Remove duplicate elements
        s.erase(unique(s.begin(), s.end()), s.end());

        // Replace each element with its rank
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
        }

        return arr;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> ans = obj.arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*The code first creates a copy of the original array so that the original order of elements is not lost. It then sorts the copied array and removes all duplicate
values, leaving only the unique elements. These unique sorted elements are used to determine the rank of each number. For every element in the original array, the 
  lower_bound() function performs a binary search on the sorted unique array to find its position. Since array indexing starts from 0, 1 is added to the index to 
obtain the rank starting from 1. Finally, the original array is updated with these ranks and returned. The overall time complexity of the algorithm is O(n log n) 
due to sorting and binary searches, while the space complexity is O(n) because of the extra copied array.*/
