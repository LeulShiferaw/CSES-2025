#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(auto &x : p) cin >> x;

    ll tot_sum = 0;
    for(auto &x : p) tot_sum += x;

    int lim = 1<<n;
    ll soln = LLONG_MAX;
    for(int i=0; i<lim; ++i) {
        ll sum = 0;
        for(int j=0; j<n; ++j) {
            if((i&(1<<j)) != 0) {
                sum += p[j];
            }
        }
        soln = min(soln, abs(tot_sum - sum - sum));
    }
    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}