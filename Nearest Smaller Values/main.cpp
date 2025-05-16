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
    for(auto &y : x) cin >> y;

    stack<pair<int, int>> prev;
    for(int i=0; i<n; ++i) {
        if(prev.size() == 0) {
            cout << "0" << " ";
        } else {
            while(prev.size() > 0 && prev.top().first >= x[i]) {
                prev.pop();
            }

            if(prev.size() == 0) {
                cout << "0" << " ";
            } else {
                cout << prev.top().second + 1 << " ";        
            }
        }
        prev.push({x[i], i});
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}