#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    // Sort the given intervals based on their starting values.
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans; // Vector to store the merged intervals.

    for (int i = 0; i < n; i++) { // Select an interval.
        int start = arr[i][0]; // Start of the current interval.
        int end = arr[i][1];   // End of the current interval.

        // Skip all the merged intervals.
        // If the current interval's end is less than or equal to the end of the last interval in ans,
        // it means they overlap, and we can skip this interval.
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        // Check the rest of the intervals for merging with the current interval.
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                // If the start of the next interval is less than or equal to the current interval's end,
                // they overlap. We can merge them by updating the end to be the maximum of both ends.
                end = max(end, arr[j][1]);
            } else {
                // If there is no overlap with the next interval, we stop checking further.
                break;
            }
        }
        
        // Add the merged interval (start, end) to the answer vector.
        ans.push_back({start, end});
    }
    
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
