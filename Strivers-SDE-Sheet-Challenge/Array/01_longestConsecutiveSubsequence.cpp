#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // For max function

using namespace std;

class Solution {
public:
    // Function to find the longest consecutive sequence in the array
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;  // Create a set to store the unique elements of the array
        
        // Insert all elements from the input vector into the set
        for (auto num : nums) {
            st.insert(num);  // This ensures that we are working with unique elements
        }
        
        int longest_sequence = 0;  // Variable to track the length of the longest consecutive sequence

        // Iterate over all the elements in the set
        for (auto num : st) {
            // Check if 'num' is the starting number of a potential sequence by checking if 'num-1' is not in the set
            if (st.find(num - 1) == st.end()) {
                int curr_sequence = 0;  // Variable to track the length of the current sequence

                // Count the length of the consecutive sequence starting from 'num'
                while (st.find(num) != st.end()) {
                    num += 1;  // Move to the next number in the sequence
                    curr_sequence += 1;  // Increment the length of the current sequence
                }

                // Update the longest sequence if the current sequence is longer
                longest_sequence = max(curr_sequence, longest_sequence);
            }
        }
        
        // Return the length of the longest consecutive sequence found
        return longest_sequence;
    }
};

int main() {
    Solution solution;
    
    // Input: array of numbers
    vector<int> nums;
    int n, input;
    
    // Read the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Read the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }
    
    // Call the longestConsecutive function and display the result
   
}