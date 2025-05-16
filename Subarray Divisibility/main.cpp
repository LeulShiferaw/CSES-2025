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

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    map<int, int> cnt;
    cnt[0]++;
    ll res = 0;
    ll curr_sum = 0;
    for(auto &x : a) {
        curr_sum += x;
        int temp = curr_sum % n;
        if(temp < 0) temp += n;
        res += cnt[temp];
        cnt[temp]++;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}