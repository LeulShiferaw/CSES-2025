#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> x(n);
    for(auto &z : x) {
        cin >> z;
    }

    auto ok = [&](const ll &val) {
        int num_reg = 1;
        ll curr = 0;
        for(int i=0; i<n; ++i) {
            curr += x[i];
            if(curr > val) {
                num_reg++;
                if(num_reg > k) return false;
                curr = x[i];
            }
        }
        return true;
    };

    ll l = accumulate(all(x), 0ll, [&](const ll &a, const ll &b) { return max(a, b); });
    ll r = accumulate(all(x), 0ll);
    ll soln = -1;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(ok(mid)) {
            soln = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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