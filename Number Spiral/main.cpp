#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int t;
    cin >> t;

    while(t--) {
        int y, x;
        cin >> y >> x;

        ll n = max(y, x);
        ll val_n = 1 + n*(n-1);
        if(y == x) {
            cout << val_n << endl;
            continue;
        } else if(y > x) {
            if(n%2 == 0) {
                val_n += abs(y-x);
            } else {
                val_n -= abs(y-x);
            }
        } else if(n%2 == 0) {
            val_n -= abs(y-x); 
        } else {
            val_n += abs(y-x);
        }

        cout << val_n << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}