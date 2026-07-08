#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                left[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        ll sum = 0;

        // Calculate contribution of every element
        for (int i = 0; i < n; i++) {
            ll leftCount = i - left[i];
            ll rightCount = right[i] - i;

            sum = (sum + (leftCount * rightCount % MOD) * nums[i]) % MOD;
        }

        return (int)sum;
    }
};

/*
Logic:

Instead of generating all possible subarrays, we calculate the contribution of each
element as the minimum of some subarrays. For every element nums[i], we find the
Previous Smaller Element (PSE) and the Next Smaller Element (NSE) using a monotonic
increasing stack. The previous smaller element tells us how many positions we can
extend to the left while keeping nums[i] as the minimum, and the next smaller element
tells us how many positions we can extend to the right. Therefore, the total number
of subarrays in which nums[i] is the minimum is:

    (i - left[i]) × (right[i] - i)

The contribution of nums[i] is:

    nums[i] × (i - left[i]) × (right[i] - i)

We compute this contribution for every element, add all contributions, and take the
result modulo 1e9+7. Since each element is pushed and popped from the stack at most
once, the overall time complexity is O(n), and the space complexity is O(n).
*/
