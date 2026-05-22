#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << endl;

const int N = 1005;
string s;
int dp[N][N];

int rec(int l, int r) {
    if(l >= r) return 0;
    
    if(dp[l][r] != -1) return dp[l][r];
    int ans = 0;
    if(s[l] == s[r]) ans += rec(l + 1, r - 1);
    else ans = min(rec(l+1, r), rec(l, r - 1)) + 1;
    return dp[l][r] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> s;
    int n = s.size();
    cout << rec(0, n - 1) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}