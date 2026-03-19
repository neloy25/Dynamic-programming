#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl << '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

int n , x[101], dp[101][10001];

int rec(int level, int left) {
    if(left < 0) return 0;

    if(level > n) {
        if(left == 0) return 1;
        else return 0;
    }

    if(dp[level][left] != -1) return dp[level][left];
    int ans = rec(level + 1, left) || rec(level + 1, left - x[level]);
    return dp[level][left] = ans;
}

void printset(int level, int left) {
    if(level > n) return;

    if(rec(level + 1, left)) {
        printset(level + 1, left);
    } else if(rec(level + 1, left - x[level])) {
        cout << x[level] << " ";
        printset(level + 1, left - x[level]);
    }
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
        if(rec(1,t)) {
            yes;
            printset(1,t);
            cout nl;
        } else {
            no;
        }
    }
    return 0;
}