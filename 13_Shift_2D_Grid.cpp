#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (!k)
            return grid;

        int r = grid.size();
        int c = grid[0].size();
        int n = r * c;

        k = k % n;

        if (!k)
            return grid;

        auto shift = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / c][i % c], grid[j / c][j % c]);
                i++;
                j--;
            }
        };

        shift(0, n - 1);
        shift(0, k - 1);
        shift(k, n - 1);

        return grid;
    }
};

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter grid elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    vector<vector<int>> result = obj.shiftGrid(grid, k);

    cout << "\nGrid after shifting:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
This program shifts all elements of a 2D grid to the right by k positions.
The 2D grid is treated as a single 1D array in row-major order.
For example, if the grid is:
1 2 3
4 5 6
7 8 9

It is considered as:
1 2 3 4 5 6 7 8 9

To perform the shift efficiently, the reversal algorithm is used.
First, the entire array is reversed.
Then, the first k elements are reversed.
Finally, the remaining elements are reversed.
This completes the right rotation in O(n) time without using extra space.
The conversion between 1D index and 2D position is:
Row = index / number_of_columns
Column = index % number_of_columns
*/
