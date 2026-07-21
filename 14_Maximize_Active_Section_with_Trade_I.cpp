#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100001;
int B[N] = {0};

class Solution {
public:
    static int maxActiveSectionsAfterTrade(string& s) {
        int cnt = 0, j = 0;
        char prev = '@';

        for (char c : s) {
            cnt += (c == '1');
            j += (prev != c && c == '0');
            B[j] += (c == '0');
            prev = c;
        }

        int adj2 = 0;
        for (int i = 1; i < j; i++) {
            adj2 = max(adj2, B[i] + B[i + 1]);
        }

        memset(B, 0, (j + 1) * sizeof(int));

        return cnt + adj2;
    }
};

int main() {
    string s;
    cin >> s;

    cout << Solution::maxActiveSectionsAfterTrade(s) << endl;

    return 0;
}


/* Code Explanation

The program finds the maximum number of active sections ('1') that can be obtained after performing one trade on the binary string.

A global array B is used to store the lengths of consecutive groups of '0' characters. The array size is fixed (100001) so it can handle large input 
efficiently without allocating memory every time. Inside the maxActiveSectionsAfterTrade() function, the variable cnt counts the total number of '1' 
characters already present in the string. The variable j represents the index of the current block of consecutive '0's, and prev stores the previous 
character so that whenever the current character changes from '1' to '0', a new zero block is detected. Each '0' encountered increases the length of 
the current zero block by updating B[j]. After all zero blocks have been recorded, the program checks every pair of adjacent zero blocks. Since a single 
trade can merge two neighboring zero blocks separated by one block of '1', it computes the maximum possible combined size of two consecutive zero blocks 
using B[i] + B[i + 1]. This value is stored in adj2. Before returning, the used portion of the global array B is reset using memset() so that multiple test 
cases do not interfere with each other. Finally, the answer is calculated as cnt + adj2, where cnt is the number of active sections already present and adj2 
is the maximum number of additional sections that can become active after the optimal trade.

Time Complexity
O(n), where n is the length of the string, because the string is traversed once and the zero-block array is scanned once.
Space Complexity
O(n) in the worst case for storing the lengths of zero blocks in the global array B.*/
