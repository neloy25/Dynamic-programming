#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> len;
    vector<ll> pos(n);

    for(int i = 0; i < n; i++) {
        if(len.empty() || v[i] > len.back()) {
            len.push_back(v[i]);
            pos[i] = len.size();
        }
        else {
            auto it = lower_bound(len.begin(), len.end(), v[i]);
            *it = v[i];
            pos[i] = it - len.begin() + 1;
        }
        cout << i << " : ";
        for(int val : len) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<int> res;
    int curlen = len.size();
    for(int i = n - 1; i >= 0; i--) {
        if(pos[i] == curlen) {
            res.push_back(v[i]);
            curlen--;
        }
    }
    reverse(res.begin(), res.end());

    for(int val : res) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    solve();
}