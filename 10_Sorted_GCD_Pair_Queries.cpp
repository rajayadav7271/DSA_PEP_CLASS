#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    using ll = long long;
    static const int N = 50001;

public:
    vector<int> gcdValues(vector<int>& A, vector<long long>& queries) {
        int mx = 0;
        int freq[N] = {0};

        for (auto &n : A) {
            freq[n]++;
            mx = max(mx, n);
        }

        ll mFreq[N] = {0};
        ll pairs[N] = {0};
        ll overlaps[N] = {0};
        ll GCD[N] = {0};

        for (int i = mx; i > 0; i--) {
            ll sum = 0;
            ll extra = 0;

            for (int j = i; j <= mx; j += i) {
                sum += freq[j];
                extra += GCD[j];
            }

            mFreq[i] = sum;
            pairs[i] = sum * (sum - 1) / 2;
            overlaps[i] = extra;
            GCD[i] = pairs[i] - overlaps[i];
        }

        for (int i = 1; i <= mx; i++)
            GCD[i] += GCD[i - 1];

        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++)
            res[i] = upper_bound(GCD, GCD + mx + 1, queries[i]) - GCD;

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int q;
    cin >> q;

    vector<long long> queries(q);

    for (int i = 0; i < q; i++)
        cin >> queries[i];

    Solution obj;
    vector<int> ans = obj.gcdValues(A, queries);

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}

/*This solution efficiently answers queries related to GCD pair values without calculating the GCD of every pair individually. First, it creates a frequency array 
where freq[x] stores how many times the number x appears in the input array. At the same time, it finds the maximum element because only values up to this maximum 
need to be processed. After that, the algorithm iterates from the largest possible GCD value down to 1. For every integer i, it counts how many array elements are 
divisible by i by checking all multiples of i. This count is stored in mFreq[i]. If there are k numbers divisible by i, then the total number of unordered pairs 
that can be formed from these numbers is k*(k-1)/2, which is stored in pairs[i]. However, some of these pairs actually have a GCD greater than i, so those pairs 
have already been counted while processing larger divisors. The variable extra accumulates these previously computed values from multiples of i, and this value 
is stored in overlaps[i]. Therefore, the number of pairs whose GCD is exactly i is calculated as pairs[i] - overlaps[i] and stored in GCD[i].*/
