/*
Problem Statement
Given an integer array nums, find the subarray with the largest sum and return its sum.

Examples
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum of 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum of 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum of 23.
Constraints
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

Solution Explanation

Algorithm:
This problem can be solved using Kadane's Algorithm, which is an efficient way to find the maximum sum of a contiguous subarray in linear time (O(n)).

Initialization:

Initialize maximum with the first element of the array.
Initialize sum to 0.
Processing:

1. Iterate through each element in the array:
2. Add the current element to sum.
3. Update maximum to be the maximum of maximum and sum.
4. If sum becomes negative, reset it to 0 because any negative sum will decrease the sum of any future subarray.

Termination:
Return the value of maximum after iterating through the entire array.



See it's prefix sum array approach. We can solve this problem in O(n) time complexity.
*/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maximum = max(sum, maximum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maximum;
    }
};