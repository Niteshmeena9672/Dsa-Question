/*
Very Important 

Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Problem Statement
You are given an array prices where prices[i] represents the price of a stock on the ith day. You want to maximize your profit by buying the stock on one day and selling it on a later day. Return the maximum profit you can achieve from this transaction. If no profit is possible, return 0.

Examples
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6). Profit = 6 - 1 = 5.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: No transactions are done, and the maximum profit = 0.
Constraints
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

Bruteforce approach can be find difference of each element with every other element and find maximum difference. But this will take O(n^2) time complexity. We can solve this problem in O(n) time complexity.

Solution Explanation
Algorithm:

1. Initialize min_value with the first element of prices.
2. Initialize curr_profit and max_profit to 0.
3. Iterate through the prices array:
4. For each price, calculate the curr_profit as the difference between the current price and the min_value.
5. Update max_profit to be the maximum of max_profit and curr_profit.
6. Update min_value to be the minimum of min_value and the current price.
7. Return max_profit.

Complexity:

Time Complexity: O(n) where n is the number of days (length of prices array).
Space Complexity: O(1) since only a few extra variables are used.

*/

// Solution:


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_value = prices[0];
        int curr_profit = 0 ;
        int max_profit = 0;
        int n = prices.size();
        for(int i = 0 ;i <n;i++){
            curr_profit = prices[i] - min_value;
            max_profit = max(max_profit, curr_profit);
            min_value = min(min_value, prices[i]);
        }   

        return max_profit;
    }
};