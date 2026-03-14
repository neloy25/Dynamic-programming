#include<bits/stdc++.h>
using namespace std;

int n;
int rec(int level) {
    if(level > n) return 0;
    if(level == n) return 1;

    int ans = 0;
    for(int step = 1; step <= 3;step++) {
        if(level + step <= n) {
            int ways = rec(level + step);
            ans += ways;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    cout << rec(1) << endl;
    return 0;
}