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

    vector<string> grid(n, "");
    for(int i=0; i<n; ++i) {
        cin >> grid[i];
    }

    deque<string> soln;
    soln.push_back(string(1, grid[grid.size()-1][grid.size()-1]));
    for(int i=n-2; i>=0; --i) {
        soln.push_front(grid[n-1][i] + soln.front());
    }

    for(int i=n-2; i>=0; --i) {
        deque<string> new_soln;
        new_soln.push_back(grid[i][n-1] + soln[n-1]);
        for(int j=n-2; j>=0; --j) {
            auto res = min(new_soln.front(), soln[j]);
            new_soln.push_front(grid[i][j] + res);
        }
        swap(new_soln, soln);
    }

    cout << soln[0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}