#include<bits/stdc++.h>
using namespace std;

int n;
int queen[20];

bool check(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(queen[i] == col || abs(queen[i] - col) == abs(row - i)) return false;
    }
    return true;
}
int rec(int row) {
    if(row == n) return 1;

    int ans = 0;
    for(int col = 0; col < n; col++) {
        if(check(row,col)) {

            queen[row] = col;

            ans += rec(row + 1);

            queen[row] = -1;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    memset(queen, -1, sizeof(queen));

    cout << rec(0);
    return 0;
}