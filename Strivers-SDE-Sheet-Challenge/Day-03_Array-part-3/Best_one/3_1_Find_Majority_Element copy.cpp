class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Create an unordered_map to store the count of occurrences of each number in the vector.
        unordered_map<int, int> map;
        
        // Variable to store the majority element (number that appears more than n/2 times).
        int ans = 0;

        // Count the occurrences of each number and store them in the map.
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // Iterate through the map to find the majority element.
        for (auto it : map) {
            // If the count of the current number (it.second) is greater than n/2,
            // it means this number is the majority element.
            if (it.second > nums.size() / 2) {
                ans = it.first;
            }
        }

        // Return the majority element found (if any).
        return ans;
    }
};


// Explanation:

// The function majorityElement takes a vector nums as input and is expected to find the majority element (the element that appears more than n/2 times in the vector).
// It uses an unordered_map called map to store the count of occurrences of each element in the vector.
// The first for loop iterates through the input vector nums and counts the occurrences of each element by incrementing the corresponding value in the map.
// The second for loop iterates through the map to find the element with a count greater than nums.size() / 2. If such an element is found, it updates the variable ans with its value.
// The function then returns the majority element stored in the variable ans.