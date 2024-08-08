#include <bits/stdc++.h>
#include <vector>

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int col=1; col<row; col++) {
        ans = ans * (row-col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<int>> ans;

    for(int i=1; i<n; i++)
    {
        ans.push_back(i);
    }

    return ans;
}
