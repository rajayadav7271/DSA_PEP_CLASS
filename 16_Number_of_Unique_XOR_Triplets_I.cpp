#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        int mask = 0;

        for (int num : nums) {
            mask |= num;
        }

        return mask + 1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution obj;

    int ans = obj.uniqueXorTriplets(nums);

    cout << "Unique XOR Triplets = " << ans << endl;

    return 0;
}


/*
Explanation:

1. We first find the size of the array.

2. If the array contains only one or two elements,
   the answer is simply the number of elements because
   there cannot be many distinct XOR triplets.

3. We initialize an integer variable 'mask' with 0.

4. We iterate through every element of the array and
   perform a bitwise OR operation:
       mask |= num;
   This sets every bit that appears in any number.

5. After processing all elements, 'mask' contains all
   bits that are present in the array.

6. If mask = 111(binary) = 7(decimal), then every XOR
   value from 0 to 7 can be produced.

7. Therefore, the total number of distinct XOR values
   is mask + 1.

Time Complexity: O(n)
- We traverse the array only once.

Space Complexity: O(1)
- Only one extra integer variable (mask) is used.
*/
