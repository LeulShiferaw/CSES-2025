#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    map<ll, int> cnt;
    ll curr_sum = 0;
    cnt[0]++;
    ll res = 0;
    for(int i=0; i<n; ++i) {
        curr_sum += a[i];
        res += cnt[curr_sum - x];
        cnt[curr_sum]++;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}