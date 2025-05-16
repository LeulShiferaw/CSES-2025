#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(auto &y : x) cin >> y;

    ll sum = x[0], curr_sum = 0;
    for(int i=0; i<n; ++i) {
        curr_sum = max(curr_sum + x[i], (ll)x[i]);
        sum = max(curr_sum, sum);
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}