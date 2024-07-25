/*

Problem Statement
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Requirements
The algorithm must run in O(n) time complexity.
Examples
Example 1:

Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore, its length is 4.

Example 2:
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest consecutive elements sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8]. Therefore, its length is 9.


Optimal Approach Using Set
Algorithm
Insert all elements from nums into an unordered set st.
Iterate through each element x in st:
If x - 1 is not in st, it means x is the start of a sequence.
Initialize cnt to 1 and current to x.
While current + 1 is in st, increment current and cnt.
Update longest with the maximum value between longest and cnt.
Code


*/
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int longestSuccessiveElements(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;

    unordered_set<int> st(a.begin(), a.end());
    int longest = 1;

    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

/*
Complexity Analysis
Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

Space Complexity: O(N), as we are using the set data structure to solve this problem.

Note: The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations. 

If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2). 
And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).
*/