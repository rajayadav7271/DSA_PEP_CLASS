#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        string ans;

        // Maintain a monotonic increasing stack
        for (char c : num) {
            while (k > 0 && !stk.empty() && stk.back() > c) {
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }

        // Remove remaining digits from the end
        while (k > 0 && !stk.empty()) {
            stk.pop_back();
            k--;
        }

        // Build answer and remove leading zeros
        for (char c : stk) {
            if (ans.empty() && c == '0')
                continue;
            ans.push_back(c);
        }

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution obj;

    string num;
    int k;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter k: ";
    cin >> k;

    string result = obj.removeKdigits(num, k);

    cout << "Smallest number after removing " << k
         << " digits = " << result << endl;

    return 0;
}
/*
Logic:
This solution uses a greedy approach with a monotonic increasing stack. We traverse each digit of the given number and remove previous larger digits whenever 
the current digit is smaller and we still have removals (`k`) left. This helps form the smallest possible number. After processing all digits, if `k` is still 
greater than 0, we remove digits from the end since they contribute the most to the value. Finally, we construct the answer by skipping leading zeros. 
If the resulting string is empty, we return "0". The overall time complexity is O(n) because each digit is pushed and popped at most once.
*/
