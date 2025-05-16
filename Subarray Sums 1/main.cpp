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

    int l=0, r=0; 
    ll sum = a[l];
    int res = 0;
    while(l <= r && r < n) {
        if(sum == x) {
            res++;
            ++r;
            if(r < n)
                sum += a[r];
        } else if(sum < x) {
            ++r;
            if(r < n) sum += a[r];
        } else {
            sum -= a[l];
            ++l;
            if(l > r) {
                ++r;
                if(r < n) sum += a[r];
            }
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