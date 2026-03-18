#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << '\n'

int n ,t , x[101], dp[101][10001];

int rec(int level, int s) {
    if(s > t) return 0;

    if(level == n) {
        if(s == t) return 1;
        else return 0;
    }

    if(dp[level][s] != -1) return dp[level][s];
    int ans = 0;
    ans = rec(level + 1, s) || rec(level + 1, s + x[level]);
    return dp[level][s] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    cout << rec(1,0);
    return 0;
}