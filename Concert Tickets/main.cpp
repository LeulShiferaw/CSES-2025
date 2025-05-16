#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> h;
    vector<int> t(m);
    for(int i=0; i<n; ++i) {
        int x;
        cin >> x;

        h.insert(x);
    }
    for(auto &x : t) cin >> x;

    for(auto &x : t) {
        auto found = h.upper_bound(x);
        if(found == h.begin()) {
            cout << -1 << endl;
            continue;
        } else {
            found--;
            cout << *found << endl;
        }
        h.erase(found);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}