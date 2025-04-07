#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int t;
    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;

        if((2*a - b)%3 == 0) {
            ll x = (2*a-b)/3;
            if((b-x)%2 == 0 && (b-x) >= 0 && x >= 0)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}