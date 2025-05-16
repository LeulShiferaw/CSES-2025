#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    deque<ll> p(n);
    for(auto &k : p) cin >> k;

    sort(p.begin(), p.end());

    int res = 0;
    while((int)p.size() > 0) {
        if(p.size() == 1) {
            ++res;
            p.pop_back();
        } else if((p.front() + p.back()) <= x) {
            ++res;
            p.pop_back();
            p.pop_front();
        } else {
            ++res;
            p.pop_back();
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}