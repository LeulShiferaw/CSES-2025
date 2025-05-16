#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> ranges(n);
    for(int i=0; i<n; ++i) {
        cin >> ranges[i].first.first >> ranges[i].first.second;
        ranges[i].second = i;
    }

    sort(ranges.begin(), ranges.end(), [](const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2) {
        if(p1.first.first == p2.first.first) {
            return p1.first.second > p2.first.second;
        }
        return p1.first.first < p2.first.first;
    });

    vector<int> tmp(n);
    multiset<int> after;
    for(int i=n-1; i>=0; i--) {
        auto val = after.upper_bound(ranges[i].first.second);
        if(val == after.begin() || after.size() == 0) {
            tmp[ranges[i].second] = 0; 
        } else tmp[ranges[i].second] = 1;
        after.insert(ranges[i].first.second);
    }

    for(auto &x : tmp) cout << x << " ";
    cout << endl;

    multiset<int> before;
    for(int i=0; i<n; ++i) {
        auto val = before.lower_bound(ranges[i].first.second);
        if(val == before.end() || before.size() == 0) {
            tmp[ranges[i].second] = 0;
        } else tmp[ranges[i].second] = 1; 
        before.insert(ranges[i].first.second);
    }

    for(auto &x : tmp) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}