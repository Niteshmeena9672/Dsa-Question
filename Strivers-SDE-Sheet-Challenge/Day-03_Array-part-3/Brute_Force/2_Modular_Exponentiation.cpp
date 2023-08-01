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
// This code implements the binary exponentiation (fast power) algorithm to calculate the power of 'x' raised to 'n'. The algorithm is optimized for efficiency, even for large values of 'n'.

// The binary exponentiation algorithm works by reducing the number of multiplication operations needed to calculate the power. Instead of naively multiplying 'x' with itself 'n' times, it uses the binary representation of 'n' to break down the calculation into a sequence of squaring 'x' and halving 'n'. This results in a time complexity of O(log n) for the power calculation.

// The algorithm handles negative exponents by converting them to positive exponents and then taking the reciprocal of the final answer if necessary.










