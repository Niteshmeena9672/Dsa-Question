#include<bits/stdc++.h>
using namespace std;

 int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int one_step = climbStairs(n - 1);
        int two_step = climbStairs(n - 2);
        return (one_step + two_step);
    }
int main(){
    int stairs;
    cin>>stairs;
    cout<<"total number of ways: "<<climbStairs(stairs)<<endl;
    return 0;
}