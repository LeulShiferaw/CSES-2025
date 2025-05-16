#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> k(n);
    for(auto &x : k) cin >> x;

    multiset<int> towers;
    for(auto &x : k) {
        auto res = towers.upper_bound(x);
        if(res == towers.end()) {
            towers.insert(x);
        } else {
            towers.erase(res);
            towers.insert(x);
        }
    }

    cout << towers.size() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}