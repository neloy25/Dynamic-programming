#include<bits/stdc++.h>
using namespace std;

int n,x,k;
int t[1001],s[1001],dp[101][101][101];


int rec(int level, int time, int item) {

    if(level == n) {
        return 0;
    }

    if(dp[level][time][item] != -1) return dp[level][time][item];

    int ans = rec(level + 1, time,item);
    if(time + t[level] <= x && item + 1 <= k) {
        ans = max(ans, rec(level + 1, time + t[level], item + 1));
    }
    return dp[level][time][item] = ans;
}

int main() {
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i = 0; i< n; i++) {
        cin >> t[i];
    }

    for(int i =0; i < n; i++) {
        cin >> s[i];
    }
    cin >> x >> k;
    return 0;
}