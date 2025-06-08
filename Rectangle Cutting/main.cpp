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
    for(int i=0; i<=a; ++i) {
        dp[i][0] = 0;
    }
    for(int i=0; i<=b; ++i) {
        dp[0][i] = 0;
    }
    for(int i=1; i<=a; ++i) {
        for(int j=1; j<=b; ++j) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }

            for(int k=1; k<=i/2; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            for(int k=1; k<=j/2; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
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