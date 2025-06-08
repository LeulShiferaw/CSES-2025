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
    int n;
    cin >> n;

    char grid[n][n];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> grid[i][j];
        }
    }

    ll soln[n][n];
    for(int i=n-1; i>=0; --i) {
        for(int j=n-1; j>=0; --j) {
            soln[i][j] = 0;
            if(grid[i][j] == '*') continue;
            if(i == (n-1) && j == (n-1)) {
                soln[i][j] = 1;
            }
            if(i+1 < n) {
                soln[i][j] += soln[i+1][j];
                soln[i][j] %= MOD;
            }
            if(j+1 < n) {
                soln[i][j] += soln[i][j+1];
                soln[i][j] %= MOD;
            }
        }
    }
    cout << soln[0][0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}