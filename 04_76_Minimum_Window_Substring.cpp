class Solution {
public:
    bool isvalid(vector<int>& occur, vector<int>& real) {
        for (int i = 0; i < 58; i++) {
            if (real[i] < occur[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        string ans = "";
        int best = INT_MAX;

        if ((int)t.size() > (int)s.size()) {
            return ans;
        }

        vector<int> occur(58, 0);

        for (char ch : t) {
            occur[ch - 'A']++;
        }

        vector<int> real(58, 0);

        int l = 0;
        int r = 0;

        while (r < (int)s.size()) {

            // Expand the window until it contains all characters of t
            while (r < (int)s.size() && !isvalid(occur, real)) {
                real[s[r] - 'A']++;
                r++;
            }

            // If still invalid, no further answer is possible
            if (!isvalid(occur, real)) {
                break;
            }

            // Shrink the window as much as possible
            while (isvalid(occur, real)) {
                real[s[l] - 'A']--;
                l++;
            }

            // Current minimum valid window is from (l-1) to (r-1)
            int len = r - l + 1;

            if (len < best) {
                best = len;
                ans = s.substr(l - 1, len);
            }
        }

        return ans;
    }
};

/*
Logic:
This solution uses the Sliding Window technique to find the minimum substring of s that contains 
every character of t. First, the frequency of each character in t is stored in the occur array, 
while the current window frequencies are maintained in the real array. The right pointer expands 
the window until all required characters are included (checked using isvalid()). Once the window 
becomes valid, the left pointer moves forward to remove unnecessary characters while keeping the 
window valid. As soon as removing one more character makes the window invalid, the previous window 
is the smallest valid window for that right boundary, so its length is compared with the best answer 
found so far. This process continues until the right pointer reaches the end of the string, ensuring 
every possible minimum valid window is considered. The overall time complexity is O(58 × N), which is 
effectively O(N) since the character set size (58) is constant.
*/
