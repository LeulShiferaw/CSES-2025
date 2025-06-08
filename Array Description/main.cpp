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
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for(auto &z : x) cin >> z;

    vector<ll> num_soln(m+1, 0);
    if(x[0] == 0) {
        fill(num_soln.begin(), num_soln.end(), 1);
    } else {
        num_soln[x[0]] = 1;
    }

    for(int i=1; i<n; ++i) {
        vector<ll> new_soln(m+1, 0);
        if(x[i] == 0) {
            for(int j=1; j<=m; ++j) {
                new_soln[j] = num_soln[j];
                if(j-1 >= 1) {
                    new_soln[j] += num_soln[j-1];
                    new_soln[j] %= MOD;
                }

                if(j+1 <= m) {
                    new_soln[j] += num_soln[j+1];
                    new_soln[j] %= MOD;
                }
            }
        } else {
            new_soln[x[i]] = num_soln[x[i]];
            if(x[i]-1 >= 1) {
                new_soln[x[i]] += num_soln[x[i]-1];
                new_soln[x[i]] %= MOD;
            }

            if(x[i]+1 <= m) {
                new_soln[x[i]] += num_soln[x[i]+1];
                new_soln[x[i]] %= MOD;
            }
        }
        swap(new_soln, num_soln);
    }

    ll soln = 0;
    for(int i=1; i<=m; ++i) {
        soln += num_soln[i];
        soln %= MOD;
    }
    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}