/*

Problem Link : https://leetcode.com/problems/sort-colors/  (imp)

Problem Description
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Examples
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
Constraints
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
Follow-up
Can you come up with a one-pass algorithm using only constant extra space?

Algorithm / Intuition
This problem is a variation of the "Dutch National Flag algorithm". The algorithm involves three pointers: low, mid, and high. The goal is to partition the array into three sections:

arr[0...low-1] contains 0s (red).
arr[low...mid-1] contains 1s (white).
arr[high+1...n-1] contains 2s (blue).

Steps
Initialize three pointers:

low = 0
mid = 0
high = n - 1
Traverse the array using the mid pointer:

If arr[mid] == 0, swap arr[low] and arr[mid], then increment both low and mid.
If arr[mid] == 1, increment mid.
If arr[mid] == 2, swap arr[mid] and arr[high], then decrement high.
Continue the loop until mid exceeds high.

Dry Run
For the array [2,0,2,1,1,0]:

Initial state: low = 0, mid = 0, high = 5
Iteration 1: Swap arr[mid] (2) with arr[high] (0). Now, nums = [0,0,2,1,1,2], high = 4.
Iteration 2: Increment low and mid as arr[mid] (0). Now, nums = [0,0,2,1,1,2], low = 1, mid = 1.
Iteration 3: Increment mid as arr[mid] (0). Now, nums = [0,0,2,1,1,2], mid = 2.
Iteration 4: Swap arr[mid] (2) with arr[high] (1). Now, nums = [0,0,1,1,2,2], high = 3.
Iteration 5: Increment mid as arr[mid] (1). Now, nums = [0,0,1,1,2,2], mid = 3.
Iteration 6: Increment mid as arr[mid] (1). Now, nums = [0,0,1,1,2,2], mid = 4.
Final sorted array: [0,0,1,1,2,2].

Code Implementation
Here is the implementation of the Dutch National Flag algorithm in C++:

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        // Traverse the array from start to end
        while (mid <= high) {
            if (nums[mid] == 0) {
                // If the element is 0, swap it with the element at 'low' pointer
                swap(nums[low], nums[mid]);
                // Increment both 'low' and 'mid' pointers
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // If the element is 1, just move the 'mid' pointer
                mid++;
            } else {
                // If the element is 2, swap it with the element at 'high' pointer
                swap(nums[mid], nums[high]);
                // Decrement the 'high' pointer
                high--;
            }
        }
    }
};


/*
Explanation
Initialize low, mid, and high.
Traverse through the array with mid pointer.
Swap elements based on the value of nums[mid] to ensure 0s are moved to the beginning, 2s to the end, and 1s stay in the middle.
Continue until the entire array is sorted in one pass with constant extra space.
This algorithm effectively sorts the array with a time complexity of O(n) and space complexity of O(1).







*/