#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int>& arr) {
        long long req = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            req = (req + arr[i] + 1) / 2;
        }
        return (int)req;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.find(arr);

    return 0;
}

/* The solution works by processing the array from the last element to the first. Instead of simulating the value of x from the beginning, it calculates the 
minimum value required before each element so that x never becomes negative during the forward process. Let req represent the minimum value needed after 
processing the current position. For each element arr[i], the required value before reaching it is calculated as ceil((req + arr[i]) / 2), which is efficiently 
implemented using integer arithmetic as (req + arr[i] + 1) / 2. This reverse computation guarantees that every step in the forward traversal keeps x non-negative 
while also ensuring the starting value is as small as possible. Since the array is traversed only once, the algorithm runs in O(n) time and uses O(1) extra space.*/
