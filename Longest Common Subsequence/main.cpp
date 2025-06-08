#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    vector<int> a(n), b(m);
    for(auto &z : a) cin >> z;
    for(auto &z : b) cin >> z;

    for(int i=0; i<=n; ++i) {
        dp[i][0] = 0;
    }

    for(int i=0; i<=m; ++i) {
        dp[0][i] = 0;
    }

    map<pair<int, int>, pair<int, int>> prev;
    function<int(int, int)> calc_dp = [&](int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i-1] == b[j-1]) {
            dp[i][j] = calc_dp(i-1, j-1) + 1;
            prev[{i, j}] = {i-1, j-1};
            return dp[i][j];
        } 
        auto val1 = calc_dp(i, j-1);
        auto val2 = calc_dp(i-1, j);

        if(val1 > val2) {
            prev[{i, j}] = {i, j-1};
            dp[i][j] = val1;
            return val1;
        } else {
            prev[{i, j}] = {i-1, j};
            dp[i][j] = val2;
            return val2;
        }
    };

    cout << calc_dp(n, m) << endl;
    auto curr = make_pair(n, m);
    vector<int> soln;
    while(curr.first != 0 && curr.second != 0) {
        if(a[curr.first-1] == b[curr.second-1]) {
            soln.push_back(a[curr.first-1]);
        }
        curr = prev[curr];
    }
    reverse(all(soln));
    for(auto &x : soln) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}