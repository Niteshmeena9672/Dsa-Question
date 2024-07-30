/*

# Notes for Problem: Set Matrix Zero

## Problem Statement
Given a matrix, if an element in the matrix is 0, set its entire row and column to 0. Return the modified matrix.

### Examples

#### Example 1:
**Input:**
```
matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
```
**Output:**
```
[[1, 0, 1], [0, 0, 0], [1, 0, 1]]
```
**Explanation:**
Since matrix[1][1] = 0, the 2nd column and 2nd row are set to 0.

#### Example 2:
**Input:**
```
matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
```
**Output:**
```
[[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]
```
**Explanation:**
Since matrix[0][0] = 0 and matrix[0][3] = 0, the 1st row, 1st column, and 4th column are set to 0.

## Brute Force Approach

### Algorithm / Intuition
1. Traverse all cells of the matrix using two nested loops.
2. If any cell (i, j) contains the value 0, mark all cells in row i and column j with -1 except those that contain 0.
3. Perform step 2 for every cell containing 0.
4. Mark all cells containing -1 with 0.

### Code (Brute Force)

```cpp
*/
#include <bits/stdc++.h>
using namespace std;

//to mark the row
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

//to mark the column
void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

// to make the matrix 0
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
```

### Complexity Analysis
- **Time Complexity:** O((N * M) * (N + M)) + O(N * M), where N = number of rows and M = number of columns. Finding the cells with 0 takes O(N * M). Marking rows and columns takes O(N + M). Finally marking cells takes O(N * M).
- **Space Complexity:** O(1), as no extra space is used.

## Better Approach

### Algorithm / Intuition
1. Declare two arrays: `row` of size N and `col` of size M, both initialized to 0.
2. Traverse all cells of the matrix using two nested loops.
3. If any cell (i, j) contains the value 0, mark the `i`th index of `row` and `j`th index of `col` as 1.
4. Traverse the entire matrix again. If either `row[i]` or `col[j]` is marked as 1, set the cell (i, j) to 0.

### Code (Better Approach)

```cpp
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    vector<int> row(n, 0); // row array
    vector<int> col(m, 0); // col array

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
```

### Complexity Analysis
- **Time Complexity:** O(2 * (N * M)), where N = number of rows and M = number of columns. We traverse the matrix twice, each traversal takes O(N * M).
- **Space Complexity:** O(N) + O(M). We use the `row` array of size N and `col` array of size M.
*/