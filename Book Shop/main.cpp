#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for(auto &x : h) cin >> x;
    for(auto &x : s) cin >> x;

    vector<ll> max_pages(x+1, 0);
    max_pages[0] = 0;
    for(int i=0; i<n; ++i) {
        for(int j=x; j>=h[i]; --j) {
            max_pages[j] = max(max_pages[j], s[i] + max_pages[j-h[i]]);
        }
    }

    cout << max_pages[x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}