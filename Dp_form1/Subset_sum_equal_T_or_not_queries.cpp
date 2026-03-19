#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << '\n'

int n , x[101], dp[101][10001];

int rec(int level, int left) {
    if(left < 0) return 0;

    if(level > n) {
        if(left == 0) return 1;
        else return 0;
    }

    if(dp[level][left] != -1) return dp[level][left];
    int ans = 0;
    ans = rec(level + 1, left) || rec(level + 1, left - x[level]);
    return dp[level][left] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        cout << rec(1,t);
    }
    return 0;
}