#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

constexpr int MOD = (int)1e9 + 7;
constexpr ll INF = (ll)1e14;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> c(n);
    for(auto &z : c) cin >> z;

    vector<ll> soln(x+1, INF);
    soln[0] = 0;

    for(int i=1; i<=x; ++i) {
        for(auto &z : c) {
            if(i-z >= 0) {
                soln[i] = min(soln[i-z] + 1, soln[i]);
            }
        }
    }

    if(soln[x] == INF) cout << -1 << endl;
    else cout << soln[x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}