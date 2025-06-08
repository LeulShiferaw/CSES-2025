#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> times(n);
    for(auto &x : times) {
        cin >> x.first >> x.second;
    }

    sort(all(times), [&](const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    int res = 0;
    multiset<int> ends;
    for(int i=0; i<n; ++i) {
        if(ends.size() == 0) {
            ++res;
            ends.insert(times[i].second);
        } else if ((*ends.begin()) <= times[i].first) {
            ++res;
            auto tmp = ends.upper_bound(times[i].first);
            advance(tmp, -1);
            ends.erase(tmp);
            ends.insert(times[i].second);
        } else if((int)ends.size() < k) {
            ends.insert(times[i].second);
            ++res;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}