#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << endl;

int n,m;
ll arr[1005][1005], dp[1005][1005];
const int MOD = 1e9 + 7;

ll rec(int i, int j) {
    if(i > n || j > m || arr[i][j] ) return 0;
    if(i == n && j == m && arr[i][j] == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    ll ans = (rec(i + 1, j) + rec(i, j + 1)) % MOD;
    return dp[i][j] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << rec(1,1) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}