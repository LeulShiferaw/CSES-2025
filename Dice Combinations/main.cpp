#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

constexpr int MOD = (int)1e9+7;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> soln(n+1, 0);
    soln[0] = 1;

    for(int i=0; i<n; ++i) {
        for(int j=6; j>=1; --j) {
            if((i+j) <= n) {
                soln[i+j] += soln[i];
                soln[i+j] %= MOD;
            }
        }
    }
    cout << soln[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}