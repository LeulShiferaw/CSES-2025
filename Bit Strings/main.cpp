#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll MOD = (ll)1e9 + 7;

void solve() {
    int n;
    cin >> n;

    ll ans = 1;
    for(int i=0; i<n; ++i) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}