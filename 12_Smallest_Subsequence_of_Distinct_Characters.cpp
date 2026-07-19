
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[27] = {0};
        bitset<27> seen;
        string st;

        // Count frequency of each character
        for (char c : s)
            freq[c & 31]++;

        // Build the smallest subsequence
        for (char c : s) {
            int x = c & 31;
            freq[x]--;

            // Skip if character is already included
            if (seen.test(x))
                continue;

            // Remove larger characters if they appear later
            while (!st.empty() && st.back() > c && freq[st.back() & 31] > 0) {
                seen.reset(st.back() & 31);
                st.pop_back();
            }

            st.push_back(c);
            seen.set(x);
        }

        return st;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Smallest Subsequence: "
         << obj.smallestSubsequence(s) << endl;

    return 0;
}

/*
Problem:
Given a string s, return the lexicographically smallest subsequence
that contains every distinct character exactly once.

Approach (Monotonic Stack):
We first count the frequency of every character in the string. Then we
traverse the string from left to right. For every character, we decrease
its remaining frequency because it has now been processed. If the
character is already present in our answer, we simply skip it because
each character must appear only once. Otherwise, before inserting the
current character, we compare it with the last character stored in our
stack (implemented using a string). If the last character is
lexicographically larger than the current character and it appears again
later in the string (its remaining frequency is greater than zero), we
remove it from the stack because placing the smaller current character
earlier will produce a smaller lexicographical answer. We also mark the
removed character as not visited. This process continues until no more
characters can be removed. Finally, we push the current character into
the stack and mark it as visited. At the end of the traversal, the stack
contains the required smallest subsequence.

Time Complexity: O(n)
Each character is pushed and popped at most one time.

Space Complexity: O(1)
Since only 26 lowercase English letters are used.
*/
