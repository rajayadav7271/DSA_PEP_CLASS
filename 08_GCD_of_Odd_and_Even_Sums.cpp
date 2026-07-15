#include <iostream>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.gcdOfOddEvenSums(n);

    return 0;
}

/*
Explanation:
The function gcdOfOddEvenSums(int n) returns the value of n directly.
The main() function creates an object of the Solution class, reads the
input value n from the user, calls the gcdOfOddEvenSums() function, and
prints the returned result. Since the function simply returns n, the
output is always equal to the input value.
*/
