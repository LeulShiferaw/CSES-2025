#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, x;
    cin >> n >> x;

    vector<pair<ll, int>> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    for(int i=0; i<n-2; ++i) {
        ll sum = x - a[i].first;
        int l = i+1, r = n-1;
        while(l < r) {
            ll curr_sum = a[l].first + a[r].first;
            if(curr_sum == sum) {
                cout << a[i].second+1 << " " << a[l].second+1 << " " << a[r].second+1 << endl;
                return;
            } else if(curr_sum > sum) {
                --r;
            } else ++l;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}