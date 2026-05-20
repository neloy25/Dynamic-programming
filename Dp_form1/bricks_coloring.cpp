#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << '\n'

const int MOD = 1e9 + 7, N = 2005;
ll n,m,k, dp[N][N];

ll rec(int level, int diff) {
    if(diff > k) return 0;
    if(level >= n) return (diff == k);

    if(dp[level][diff] != -1) return dp[level][diff];
    ll ans = 0;

    ans = (ans + rec(level + 1, diff)) % MOD;
    if(diff < k) ans = (ans + ((m - 1) * rec(level + 1, diff + 1)) % MOD) % MOD;
    return dp[level][diff] = ans;
}

void solve() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    cout << (m * rec(1,0)) % MOD nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}