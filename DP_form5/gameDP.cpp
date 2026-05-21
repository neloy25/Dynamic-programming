/*
This is Game DP

If I can make my opponent lose in any move,
then I will win.

There are x marbles.
In one move, a player can take y marbles,
where y = 2^m

The player who cannot move loses.

State:
dp(x) = whether current player wins with x marbles

Transition:
If there exists any move y such that
dp(x - y) == false,
then dp(x) = true
*/

#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int rec(int x) {
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];

    int ans = 0;

    for(int i = 0; (1 << i) <= x; i++) {
        int y = (1 << i);
        if(rec(x - y) == 0) {
            ans = 1;
            break;
        }
    }

    return dp[x] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    if(rec(n)) cout << "First player wins\n";
    else cout << "Second player wins\n";
    return 0;
}