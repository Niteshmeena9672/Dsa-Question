#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    // Sort the given intervals based on their starting values.
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans; // Vector to store the merged intervals.

    for (int i = 0; i < n; i++) {
        // If the current interval does not
        // overlap with the last interval in the answer vector,
        // we can directly add it to the answer.
        // (Or if the answer vector is empty, we add the first interval.)
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // If the current interval overlaps with the last interval,
        // we can merge them by updating the end of the last interval.
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
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
