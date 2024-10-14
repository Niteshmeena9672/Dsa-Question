#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    unordered_set<string> st; // Using an unordered set for O(1) lookup.

    // Recursive function to check if the string can be segmented. 
    // `idx` is the current index in the string, `memo` is used for memoization.
    bool solve(int idx, string &s, vector<int>& memo) {
        int n = s.length();

        // Base case: If the index reaches the end of the string, return true.
        if (idx >= n) {
            return true;
        }

        // If the result is already calculated, return the stored result.
        if (memo[idx] != -1) return memo[idx];

        // Check for every possible substring starting from the current index.
        for (int l = 1; l <= n - idx; l++) {
            string temp = s.substr(idx, l);  // Create substring starting from idx with length l.

            // If the substring is in the set and we can solve the remaining part recursively.
            if (st.find(temp) != st.end() && solve(idx + l, s, memo)) {
                return memo[idx] = true;
            }
        }

        // If no valid segmentation is found, return false.
        return memo[idx] = false;
    }

    // Main function to check if the string `s` can be segmented into words from `wordDict`.
    bool wordBreak(string s, vector<string>& wordDict) {
        // Store all words from `wordDict` in an unordered set for O(1) lookups.
        for (auto &word : wordDict) {
            st.insert(word);
        }

        // Memoization array initialized with -1 (uncomputed state).
        vector<int> memo(s.length(), -1);

        // Start the recursive solution from the beginning of the string.
        return solve(0, s, memo);
    }
};

int main() {
    // Input string
    string s;
    cout << "Enter the string: ";
    cin >> s;

    // Input word dictionary
    int n;
    cout << "Enter the number of words in the dictionary: ";
    cin >> n;

    vector<string> wordDict(n);
    cout << "Enter the words in the dictionary:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    // Create an instance of the Solution class
    Solution solution;

    // Call the wordBreak function and display the result
    if (solution.wordBreak(s, wordDict)) {
        cout << "The string can be segmented into a space-separated sequence of dictionary words." << endl;
    } else {
        cout << "The string cannot be segmented into dictionary words." << endl;
    }

    return 0;
}
