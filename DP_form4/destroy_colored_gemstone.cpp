#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << endl;
ll n, v[105], dp[120][120];

// ll rec(int i, int j) {
//     if(i == j) return 1;
//     if(i > j) return 0;

//     if(dp[i][j] != -1) return dp[i][j];

//     ll ans = 1 + rec(i + 1, j);

//     if(v[i] == v[i + 1]) ans = min(ans, 1 + rec(i + 2,j));

//     for(int k = i + 2; k <= j; k++) {
//         if(v[i] == v[k]) ans = min(ans, rec(i + 1, k - 1) + rec(k + 1, j));
//     }
//     return dp[i][j] = ans;
// }


void solve() {
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for(int i = 0; i <= n + 15; i++) {
        for(int j = 0; j <= n + 15; j++) {
            if(i == j) dp[i][j] = 1;
            if(i > j) dp[i][j] = 0;
        }
    }

    // for interval dp, always len loop 
    for(int len = 2; len <= n; len++) {

        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            dp[i][j] = dp[i + 1][j] + 1;

            if(v[i] == v[i + 1]) 
                dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
            
            for(int k = i + 2; k <= j; k++) {
                if(v[i] == v[k]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                }
            }
        }
    }
    
    cout << dp[0][n - 1] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}