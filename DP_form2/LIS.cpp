// Find the longest increasing subsequence using form2
/* 
1. State
dp(level) = best from 1 to level + 1

2. Transition
dp[level] = max(dp[1]...dp[level - 1]) + 1; in which arr[level] > arr[taken] 

*/

#include<bits/stdc++.h>
using namespace std;

int dp[1001],arr[1001];

int rec(int level) {
    if(level == 0) return 1;
    if(dp[level] != -1) return dp[level];
    dp[level] = 1;
    for(int prev = 0; prev < level; prev++) {
        if(arr[level] > arr[prev])
            dp[level] = max(dp[level],1 + rec(prev));
    }
    return dp[level];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = -1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, rec(i));
    }
    cout << ans << endl;
}