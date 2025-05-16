#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> x(n);
    for(auto &y : x) cin >> y;

    sort(x.begin(), x.end());

    ll curr_n = 0;
    for(int i=0; i<n; ++i) {
        if((curr_n - x[i] + 1) < 0) {
            cout << curr_n + 1 << endl;
            return;
        } else {
            curr_n += x[i];
        }
    }
    cout << curr_n + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}