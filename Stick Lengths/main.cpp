#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> p(n);
    for(auto &x : p) cin >> x;

    auto ok = [&](ll length) {
        ll res = 0;
        for(auto &x : p) {
            res += abs(x - length);
        }
        return res;
    };

    ll soln = LLONG_MAX;
    ll l = 1, h = (ll)1e9;
    while(l <= h) {
        ll mid = (l+h)/2;
        ll val1 = ok(mid-1);
        ll val2 = ok(mid);
        ll val3 = ok(mid+1);
        if((val2 <= val1) && (val2 <= val3)) {
            soln = val2;
            break;
        } else if((val1 <= val2) && (val1 <= val3)) {
            soln = val1;
            h = mid-1;
        } else {
            soln = val3;
            l = mid+1;
        }
    }

    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}