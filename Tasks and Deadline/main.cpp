#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for(auto &x : tasks) cin >> x.first >> x.second;

    sort(tasks.begin(), tasks.end());

    ll f = 0, reward = 0;
    for(auto &x : tasks) {
        f += x.first;
        reward += x.second - f;
    }

    cout << reward << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}