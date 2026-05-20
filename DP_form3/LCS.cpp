/*
this is multi sequence dp

state: dp(i,j)
transition: dp(i,j) 
    1. dp(i + 1, j)
    2. dp(i, j + 1)
    3. if(x == y) 1 + dp(i + 1, j + 1)
ans = max(1,2,3);
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
string s,t;
int dp[1001][1001];
int rec(int i, int j) {
    if(i >= n || j >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;

    ans = max(rec(i + 1, j), rec(i, j + 1));
    if(s[i] == t[j]) {
        ans = max(ans, 1 + rec(i + 1, j + 1));
    }

    return dp[i][j] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    cin >> s >> t;
    cout << rec(0,0);
}