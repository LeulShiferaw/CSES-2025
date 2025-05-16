#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    char board[8][8];
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            cin >> board[i][j];
        }
    }

    int res = 0;
    vector<bool> col_taken(8, false), diag1_taken(15, false), diag2_taken(15, false);
    function<void(int)> calc = [&](int row) {
        if(row == 8) {
            res++;
            return;
        }

        for(int i=0; i<8; ++i) {
            if(board[i][row] == '*') continue;
            if(col_taken[i]) continue;
            if(diag1_taken[i-row+7]) continue;
            if(diag2_taken[i+row]) continue;

            col_taken[i] = true;
            diag1_taken[i-row+7] = true;
            diag2_taken[i+row] = true;
            calc(row+1);
            col_taken[i] = false;
            diag1_taken[i-row+7] = false;
            diag2_taken[i+row] = false;
        }
    };

    calc(0);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}