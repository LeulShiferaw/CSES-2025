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

    vector<int> x(n);
    for(auto &z : x) cin >> z;

    ll dp[5000][5000][2];
    fill(&dp[0][0][0], &dp[0][0][0] + 5000 * 5000 * 2, LLONG_MAX);
    vector<ll> prefix_sum(n, 0);
    prefix_sum[0] = x[0];
    for(int i=1; i<n; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + x[i];
    } 

    auto calc_between = [&](int a, int b) {
        ll res = prefix_sum[b];
        if(a-1 >= 0) {
            res -= prefix_sum[a-1];
        }
        return res;
    };

    auto switch_turn = [](const int &turn) {
        if(turn == 0) return 1;
        return 0;
    };

    function<ll(int, int, int)> calc_dp = [&](int a, int b, int turn) -> ll {
        if(dp[a][b][turn] != LLONG_MAX) return dp[a][b][turn];
        if(a == b) {
            dp[a][a][turn] = x[a];
            dp[a][a][switch_turn(turn)] = x[a];
            return x[a];
        }

        auto val = x[a] + calc_between(a+1, b) - calc_dp(a+1, b, switch_turn(turn));
        val = max(val, x[b] + calc_between(a, b-1) - calc_dp(a, b-1, switch_turn(turn)));
        dp[a][b][turn] = val;
        return val;
    };

    calc_dp(0, n-1, 0);
    cout << dp[0][n-1][0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}