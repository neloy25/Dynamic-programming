#include<bits/stdc++.h>
using namespace std;

int n,x,k;
int t[1001];
int s[1001];

bool taken[1001];

bool check(int level) {
    int timetaken = 0;
    int itemtaken = 0;
    for(int i = 0; i < level; i++) {
        if(taken[i]) {
            timetaken += t[i];
            itemtaken += 1;
        }
    }

    timetaken += t[level];
    itemtaken += 1;
    if(timetaken <= x && itemtaken <= k) return true;
    return false;
}

int rec(int level) {

    if(level == n) return 0;

    int ans = rec(level+1);

    if(check(level)) {
        taken[level] = true;
        ans = max(ans, s[level] + rec(level+1));
        taken[level] = false;
    }

    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i< n; i++) {
        cin >> t[i];
    }

    for(int i =0; i < n; i++) {
        cin >> s[i];
    }
    cin >> x >> k;
    return 0;
}