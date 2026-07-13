#include <iostream>
#include <vector>
using namespace std;

int searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return 1;
        }
        else if (matrix[row][col] > target) {
            col--;
        }
        else {
            row++;
        }
    }

    return 0;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target;
    cin >> target;

    if (searchMatrix(matrix, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}

/* This algorithm efficiently searches for a target element in a matrix where every row is sorted in increasing order from left to right and every column is 
sorted in increasing order from top to bottom. The search starts from the top-right corner of the matrix because this position allows us to eliminate either 
a row or a column in every comparison. Initially, row is set to 0 and col is set to the index of the last column. If the current element is equal to the target, 
the function immediately returns 1, indicating that the target is found. If the current element is greater than the target, all elements below it in the same 
column are even larger, so the algorithm moves one column to the left (col--). If the current element is smaller than the target, all elements to its left in 
the same row are also smaller, so the algorithm moves one row downward (row++). This process continues until the target is found or the search goes outside the
matrix boundaries, in which case the function returns 0. Since each step removes either one row or one column from consideration, the algorithm performs at most 
m + n comparisons for an m × n matrix. Therefore, the time complexity is O(m + n), while the space complexity is O(1) because it uses only two integer variables 
regardless of the matrix size.*/
