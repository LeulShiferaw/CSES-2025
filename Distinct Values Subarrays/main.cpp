#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(auto &z : x) cin >> z;

    map<int, int> cnt;
    ll soln = 0;
    int l=0, r=0;
    while(r < n) {
        cnt[x[r]]++;
        if(cnt[x[r]] > 1) {
            while(true) {
                if(cnt[x[l]] > 1) {
                    cnt[x[l]]--;
                    ++l;
                    break;
                } else {
                    cnt[x[l]]--;
                    ++l;
                }
            }
        }
        soln += r-l+1;
        ++r;
    }
    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}