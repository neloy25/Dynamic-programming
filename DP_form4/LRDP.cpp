#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
vector<int> x;

int rec(int l, int r) {
    if(r - l <= 1) return 0;
    if(dp[l][r] != -1)
        return dp[l][r];

    int ans = INT_MAX;

    for(int p = l + 1; p < r; p++) {
        int cost =(x[r] - x[l])+ rec(l, p)+ rec(p, r);
        ans = min(ans, cost);
    }

    return dp[l][r] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;

    x.resize(m + 2);

    x[0] = 0;
    for(int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    x[m + 1] = n;

    cout << rec(0, m + 1);
}