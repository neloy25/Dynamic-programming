#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll dp[1001][8];
string s = "0100";

ll rec(ll i, ll k) {
    if(i >= n) return 1;
    if(dp[i][k] != -1) return dp[i][k];

    ll ans = 0;
    ll tmp = k * 2;
    if(tmp >= 8) tmp-= 8;

    if(i < 3 || k != 2) {
        ans += rec(i + 1, tmp);
    }
    ans += rec(i + 1, tmp + 1);
    return dp[i][k] = ans;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0,0) << endl;
}