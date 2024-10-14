#include <iostream>
#include <vector>
using namespace std;

// Recursive approach (inefficient for large n)
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Memoization approach (efficient with O(n) time complexity)
int fibonacci_memoization(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) return dp[n]; // If already computed, return the cached value
    dp[n] = fibonacci_memoization(n - 1, dp) + fibonacci_memoization(n - 2, dp);
    return dp[n];
}

// Tabulation approach (most efficient with O(n) time complexity and O(n) space complexity)
int fibonacci_tabulation(int n, vector<int>& dp) {
    dp[0] = 0;
    if (n > 0) dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int nth_fibonacci;
    
    // Take input with user-friendly prompt
    cout << "Enter the nth Fibonacci number to find: ";
    cin >> nth_fibonacci;
    
    // Handle invalid input (like negative numbers)
    if (nth_fibonacci < 0) {
        cout << "Fibonacci of a negative number is undefined." << endl;
        return 1;
    }
    
    // Uncomment the desired method of calculation
    
    // Recursive approach (inefficient for large values of n)
    // cout << "nth Fibonacci number (Recursive): " << fibonacci_recursive(nth_fibonacci) << endl;

    // Memoization approach (dynamic programming)
    vector<int> dp(nth_fibonacci + 1, -1);
    // cout << "nth Fibonacci number (Memoization): " << fibonacci_memoization(nth_fibonacci, dp) << endl;

    // Tabulation approach (iterative dynamic programming)
    cout << "nth Fibonacci number (Tabulation): " << fibonacci_tabulation(nth_fibonacci, dp) << endl;

    return 0;
}
