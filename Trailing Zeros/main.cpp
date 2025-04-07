#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    int pow_5 = 1;
    ll res = 0;
    for(int i=0; i<13; ++i) {
        pow_5 *=5;
        res += n/pow_5;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}