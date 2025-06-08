#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n;
    cin >> n;

    vector<int> soln(n+1, 0);
    soln[0] = 0;

    for(int i=1; i<=n; ++i) {
        auto num_str = to_string(i);
        soln[i] = INT_MAX;
        for(auto &ch : num_str) {
            soln[i] = min(soln[i], soln[i-(ch-'0')] + 1);
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