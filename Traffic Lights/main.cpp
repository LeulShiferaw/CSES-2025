#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
    There is a bug in the problem statement. I sent an email to the writier (Antti Laaksonen)
*/

void solve() {
    int x, n;
    cin >> x >> n;

    vector<int> p(n);
    for(auto &x : p) cin >> x;

    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    multiset<int> lengths;
    lengths.insert(x);

    for(auto &v : p) {
        auto right = lights.lower_bound(v);
        auto left = lights.lower_bound(v);
        advance(left, -1);

        lengths.erase(lengths.find(*right - *left));
        lengths.insert(*right - v);
        lengths.insert(v - *left);
        lights.insert(v);

        cout << *lengths.rbegin() << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}