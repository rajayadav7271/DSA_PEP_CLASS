#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int mx = 0;

        for (auto &n : A) {
            mx = max(mx, n);
            n = gcd(n, mx);
        }

        sort(A.begin(), A.end());

        long long res = 0;
        int i = 0;
        int j = A.size() - 1;

        while (i < j) {
            res += gcd(A[i], A[j]);
            i++;
            j--;
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Solution obj;
    cout << obj.gcdSum(A);

    return 0;
}

/*
The program calculates the GCD Pair Sum of an array. First, it finds the
maximum element while updating each array element with the GCD of itself
and the current maximum value. After that, the array is sorted in ascending
order. Finally, the first and last elements are paired together, then the
second and second-last elements, and so on. The GCD of each pair is added
to obtain the final result, which is printed as output.
*/
