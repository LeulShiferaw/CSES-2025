#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            vector<bool> used(4, false);
            used[grid[i][j]-'A'] = true;
            if((i-1) >= 0) {
                used[grid[i-1][j]-'A'] = true;
            }

            if((j-1) >= 0) {
                used[grid[i][j-1]-'A'] = true;
            }

            for(int k=0; k<4; ++k) {
                if(!used[k]) {
                    grid[i][j] = 'A' + k;
                    break;
                }
            }
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}