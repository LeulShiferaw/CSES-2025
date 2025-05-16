#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    ll n, t;
    cin >> n >> t;

    vector<ll> k(n);
    for(auto &x : k) cin >> x;

    auto calc = [&](const ll &time) {
        ll res = 0;
        for(auto &x : k) {
            res += time/x;
        }
        return res;
    };

    ll l = 1, h = 1;
    while(calc(h) < t) {
        h*=2;
    }
    ll soln = 0;
    while(l <= h) {
        ll mid = (l+h)/2;
        auto val = calc(mid);
        if(val < t) {
            l = mid+1;
        } else {
            soln = mid;
            h = mid - 1;
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