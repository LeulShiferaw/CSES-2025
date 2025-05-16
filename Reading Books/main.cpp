#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*
    I have loosely proved in my head that we need to sort the first person's books
    Then we need to move the last item to first and keep everything else sorted for the second person
    Just shift the last item to the first. 

    The proof is that for the two order to go to reach the same item is simply impossible.
*/

void solve() {
    int n;
    cin >> n;

    vector<int> t(n);
    ll total = 0;
    for(auto &x : t) {
        cin >> x;
        total += x;
    }

    sort(t.begin(), t.end());

    cout << max(2ll*t.back(), total) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}