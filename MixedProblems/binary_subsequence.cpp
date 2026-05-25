#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll dp[1001][4];
ll rec(ll i, ll k) {
    if(k == 4) return 0;
    if(i >= n) return 1;
    if(dp[i][k] != -1) return dp[i][k];

    return dp[i][k] = rec(i + 1, k) + rec(i + 1, k + 1);
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0,0) << endl;
}