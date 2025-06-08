#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

constexpr int MOD = (int)1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for(auto &z : c) cin >> z;

    vector<int> vals(x+1, 0);
    vals[0] = 1;
    for(int j=0; j<n; ++j) {
        for(int i=c[j]; i<=x; ++i) {
            vals[i] += vals[i-c[j]];
            if(vals[i] < 0) vals[i] += MOD;
            if(vals[i] >= MOD) vals[i]-=MOD;
        }
    }

    cout << vals[x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}