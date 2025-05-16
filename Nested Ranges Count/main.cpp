#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*
    Lower bound and upper bound are switched for indexed set.
    is.lower_bound - finds strictly greater than
    is.upper_bound - finds greater or equal to

    1. sort the elements by increasing first element and decreasing second element
    2. Go through elements from top to bottom for the second task and bottom to top for the first task
*/

void solve() {
    /*
    indexed_set is;
    is.insert(2);
    is.insert(2);
    is.insert(1);
    is.insert(3);
    cout << *is.upper_bound(2) << endl;
    return;
    */

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
    indexed_set after;
    for(int i=n-1; i>=0; i--) {
        auto val = after.lower_bound(ranges[i].first.second);
        //auto val  = upper_bound(after.begin(), after.end(), ranges[i].first.second);
        if(val == after.begin() || after.size() == 0) {
            tmp[ranges[i].second] = 0; 
        } else {
            if(val == after.end()) {
                tmp[ranges[i].second] = after.size();
            } else {
                tmp[ranges[i].second] = after.order_of_key(*val);
            }
        }
        after.insert(ranges[i].first.second);
    }

    for(auto &x : tmp) cout << x << " ";
    cout << endl;

    indexed_set before;
    for(int i=0; i<n; ++i) {
        auto val = before.upper_bound(ranges[i].first.second);
        //auto val = lower_bound(before.begin(), before.end(), ranges[i].first.second);

        if(val == before.end() || before.size() == 0) {
            tmp[ranges[i].second] = 0;
        } else {
            if(val == after.end()) {
                tmp[ranges[i].second] = 0;
            } else {
                tmp[ranges[i].second] = before.size() - before.order_of_key(*val);
            }
        }
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