class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityThreshold = nums.size() / 2; // Threshold to check if an element is the majority element.

        for (int i = 0; i < nums.size(); i++) {
            int count = 0; // Variable to count occurrences of the current element.

            // Count the occurrences of the current element in the vector.
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            // If the count is greater than the threshold, the current element is the majority element.
            if (count > majorityThreshold) {
                return nums[i]; // Return the majority element found.
            }
        }

        // If no majority element is found, return -1 (or any other appropriate default value).
        // This is assuming that the input vector always has a majority element.
        return -1;
    }
};

// Explanation:

// The function majorityElement takes a vector nums as input and is expected to find the majority element (the element that appears more than n/2 times in the vector).
// The majorityThreshold is set to nums.size() / 2, which represents the minimum count required for an element to be considered a majority element.
// The function uses two nested loops to compare each element with all other elements in the vector.
// The outer loop iterates through the vector elements, considering each element as a potential majority element candidate.
// The inner loop counts the occurrences of the current element in the vector.
// If the count of the current element is greater than the majorityThreshold, the current element is considered the majority element, and it is returned.
// If no majority element is found after iterating through the entire vector, the function returns -1 (or any other appropriate default value).