#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    string w1, w2;
    cin >> w1 >> w2;

    vector<vector<int>> dp(w1.size() + 1, vector<int>(w2.size() + 1, -1));
    for(int i=0; i<(int)w2.size() + 1; ++i) {
        dp[0][i] = i;
    }
    for(int i=0; i<(int)w1.size() + 1; ++i) {
        dp[i][0] = i;
    }
    function<int(int, int)> calc_dp = [&](int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        auto res = max(i, j);
        res = min(res, calc_dp(i-1, j) + 1);
        res = min(res, calc_dp(i, j-1) + 1);
        res = min(res, calc_dp(i-1, j-1) + ((w1[i-1] == w2[j-1]) ? 0 : 1));
        dp[i][j] = res;
        return res;
    };

    cout << calc_dp(w1.size(), w2.size()) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}