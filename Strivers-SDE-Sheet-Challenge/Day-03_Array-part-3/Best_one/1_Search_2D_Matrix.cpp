class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Check if the matrix is empty
        if (!matrix.size()) return false;
        
        // Get the number of rows and columns in the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Set the search range from 0 to n*m-1
        int lo = 0;
        int hi = n * m - 1;

        // Binary search loop
        while (lo <= hi) {
            // Calculate the mid point of the search range
            int mid = lo + (hi - lo) / 2;

            // Convert mid back to matrix indices (row and column)
            int row = mid / m;
            int col = mid % m;

            // Check if the value at the mid point is equal to the target
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                // If the value at the mid point is less than the target,
                // narrow the search range to the upper half of the matrix
                lo = mid + 1;
            }
            else {
                // If the value at the mid point is greater than the target,
                // narrow the search range to the lower half of the matrix
                hi = mid - 1;
            }
        }

        // If the target is not found, return false
        return false;
    }
};
