#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << endl;

ll dp[1005][1005],arr[1005][1005];
void solve() {
    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) + arr[i][j];
        }
    }

    cout << dp[n][m] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}