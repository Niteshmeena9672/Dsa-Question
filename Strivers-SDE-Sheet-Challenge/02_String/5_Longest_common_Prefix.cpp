#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the longest common prefix
    string longestCommonPrefix(vector<string>& strs) {
        // Sort the array of strings
        sort(strs.begin(), strs.end());
        
        string ans = "";            // Initialize the answer string
        string first = strs[0];      // First string after sorting
        string last = strs[strs.size()-1]; // Last string after sorting
        
        // Compare characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If characters don't match, return the answer so far
            if (first[i] != last[i]) {
                return ans;
            }
            // Append matching characters to the answer
            ans += first[i];
        }
        return ans;  // Return the longest common prefix
    }
};

int main() {
    int n;  // Number of strings in the input
    cout << "Enter the number of strings: ";
    cin >> n;
    
    vector<string> strs(n);  // Create a vector to store strings
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    Solution solution;
    string result = solution.longestCommonPrefix(strs);  // Get the longest common prefix
    
    // Output the result
    if(result.empty()) {
        cout << "No common prefix found." << endl;
    } else {
        cout << "Longest common prefix: " << result << endl;
    }
    
    return 0;
}
