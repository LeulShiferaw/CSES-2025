#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, a+b));
    for(int i=1; i<=a; ++i) {
        for(int j=1; j<=b; ++j) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }

            if(a == 1) {
                dp[i][j] = j;
                continue;
            }

            for(int k=1; k<=a/2; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[a-k][j] + 1);
            }
            for(int k=1; k<=b/2; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][b-k] + 1);
            }
        }
    }

    cout << dp[a][b] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
