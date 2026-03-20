#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n,k,w,weight[101],val[101];
ll dp[101][11][1001];

ll rec(int i, int j, int rem) {
    if(i >= n) return 0;

    if(dp[i][j][rem] !=  -1) return dp[i][j][rem];
    ll ans = 0;
    ans = max(ans, rec(i + 1, 0, rem));
    
    if(j < k && rem - weight[i] >= 0) {
        ans = max(ans, val[i] + rec(i + 1, j + 1, rem - weight[i]));
    }

    return dp[i][j][rem] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> w;
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> val[i];

    cout << rec(0,0,w) << endl;
    return 0;
}