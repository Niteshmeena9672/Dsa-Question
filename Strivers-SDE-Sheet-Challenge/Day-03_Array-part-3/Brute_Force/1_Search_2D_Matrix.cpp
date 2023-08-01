class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Check if the matrix is empty
        if (!matrix.size()) return false;
        
        // Get the number of rows and columns in the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Iterate through each element in the matrix to find the target
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Compare the current element with the target
                if (matrix[i][j] == target) {
                    // If the target is found, return true
                    return true;
                }
            }
        }

        // If the target is not found after checking all elements, return false
        return false;
    }
};
