class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // Convert 'n' to a long long variable to handle negative integer overflow

        // If 'n' is negative, convert it to a positive number for easier calculations
        if (nn < 0) {
            nn = -1 * nn;
        }

        // Exponentiation using binary exponentiation (fast power) algorithm
        while (nn) {
            // If 'n' is odd, multiply the answer by 'x' and reduce 'n' by 1
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                // If 'n' is even, square 'x' and divide 'n' by 2
                x = x * x;
                nn = nn / 2;
            }
        }

        // If the original 'n' was negative, take the reciprocal of the answer
        if (n < 0) {
            ans = 1 / ans;
        }

        // Return the final answer
        return ans;
    }
};


This code implements the binary exponentiation (fast power) algorithm to calculate the power of 'x' raised to 'n'. The algorithm is optimized for efficiency, even for large values of 'n'.

The binary exponentiation algorithm  works by reducing the number of multiplication operations needed to calculate the power. Instead of naively multiplying 'x' with itself 'n' times, it uses the binary representation of 'n' to break down the calculation into a sequence of squaring 'x' and halving 'n'. This results in a time complexity of O(log n) for the power calculation. The algorithm handles negative exponents by converting them to positive exponents and then taking the reciprocal of the final answer if necessary.
