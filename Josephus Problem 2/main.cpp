#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n, k;
    cin >> n >> k;

    indexed_set is;
    for(int i=1; i<=n; ++i) {
        is.insert(i);
    }

    int curr = 0;
    while(is.size() > 0) {
        curr += k;
        curr %= is.size();
        auto val = is.find_by_order(curr);
        cout << *val << endl;
        is.erase(val);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}