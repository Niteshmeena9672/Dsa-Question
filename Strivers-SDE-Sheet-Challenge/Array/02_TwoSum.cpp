#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to find two indices such that the numbers at those indices sum to the target
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    // Create a vector of pairs to store the value and its original index
    vector<pair<int, int>> indexedNums(n);
    for (int i = 0; i < n; ++i) {
        indexedNums[i] = {nums[i], i}; // Store value and original index
    }

    // Sort the vector of pairs based on the values
    sort(indexedNums.begin(), indexedNums.end());

    int start = 0, end = n - 1; // Initialize two pointers
    while (start < end) {
        int sum = indexedNums[start].first + indexedNums[end].first; // Calculate the sum of the two numbers
        
        // Debug statement to see the current sum
        cout << "sum: " << sum << endl;
        
        if (sum == target) {
            // Return the original indices of the two numbers that sum to the target
            return {indexedNums[start].second, indexedNums[end].second};
        } else if (sum > target) {
            end--; // Decrease end pointer if sum is greater than target
        } else {
            start++; // Increase start pointer if sum is less than target
        }
    }

    return {-1, -1}; // Return {-1, -1} if no solution is found
}

int main() {
    int target;
    cin >> target; // Input target value
    int n;
    cin >> n; // Input number of elements
    vector<int> nums;

    // Input each number into the vector
    while (n--) {
        int number;
        cin >> number;
        nums.push_back(number);
    }

    // Call the twoSum function and store the result
    vector<int> result = twoSum(nums, target); 

    // Output the result
    if (result[0] != -1) {
        cout << "Indices: " << result[0] << " " << result[1] << endl; // Print the indices of the two numbers
    } else {
        cout << "No solution found." << endl; // Handle case where no solution exists
    }

    return 0;
}
