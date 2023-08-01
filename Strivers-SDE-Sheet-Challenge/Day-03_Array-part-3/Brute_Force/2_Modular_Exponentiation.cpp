class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        // Check if 'n' is negative
        if (n < 0) {
            // If 'n' is negative, take the reciprocal of 'x'
            x = 1 / x;
            // Convert 'n' to a positive number for easier calculations
            n = -n;
        }

        // Naive approach: multiply 'x' by itself 'n' times
        for (int i = 0; i < n; ++i) {
            ans = ans * x;
        }

        // Return the final answer
        return ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        // Check if 'n' is negative
        if (n < 0) {
            // If 'n' is negative, take the reciprocal of 'x'
            x = 1 / x;
            // Convert 'n' to a positive number for easier calculations
            n = -n;
        }

        // Naive approach: multiply 'x' by itself 'n' times
        for (int i = 0; i < n; ++i) {
            ans = ans * x;
        }

        // Return the final answer
        return ans;
    }
};
// The naive approach calculates the power of 'x' by multiplying 'x' by itself 'n' times. This approach has a time complexity of O(n) since it performs 'n' multiplications. It handles negative exponents by taking the reciprocal of 'x' and converting 'n' to a positive number before the multiplication loop.

// While the naive approach is straightforward, it may not be efficient for large values of 'n'. The binary exponentiation algorithm in the previous optimized code takes O(log n) time and is a more efficient approach for calculating the power of 'x' raised to 'n', especially for larger values of 'n'.





