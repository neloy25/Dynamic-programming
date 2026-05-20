#include<bits/stdc++.h>
using namespace std;

vector<string> res;
string s;
int sc; 
int n;
void rec(int i) {
    if(i > n) return;
    if(i == n && sc == 0) {
        res.push_back(s);
        return;
    }

    s.push_back('(');
    sc++;
    rec(i + 1);
    sc--;
    s.pop_back();
    if(sc > 0) {
        s.push_back(')');
        sc--;
        rec(i + 1);
        sc++;
        s.pop_back();
    }
}

int main() {
    cin >> n;
    rec(0);
    for(string val : res) {
        cout << val << endl;
    }
    cout << endl;
}