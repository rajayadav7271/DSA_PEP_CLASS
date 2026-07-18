#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        return gcd(mn, mx);
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "GCD of the smallest and largest element is: "
         << obj.findGCD(nums) << endl;

    return 0;
}


/*This program finds the Greatest Common Divisor (GCD) of the smallest and largest elements in an array. The findGCD() function first uses the min_element() 
function to locate the smallest value in the vector and max_element() to locate the largest value. These two values are then passed to the gcd() function. 
The gcd() function implements the Euclidean Algorithm, which repeatedly replaces the larger number with the remainder obtained after dividing it by the smaller 
number. This process continues until the second number becomes 0. At that point, the first number is the greatest common divisor. In the main() function, the 
user is asked to enter the number of elements and the array values. A Solution object is created, and the findGCD() function is called to compute the answer, 
which is then displayed on the screen. The overall time complexity is O(n + log(max)), where O(n) is required to find the minimum and maximum elements in the 
array and O(log(max)) is required by the Euclidean algorithm to compute the GCD. The space complexity is O(1) because only a few extra variables are used 
regardlessof the input size.*/
