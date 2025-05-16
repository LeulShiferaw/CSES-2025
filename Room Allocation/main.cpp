#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*
    Kinda complicated
*/

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> end_times(n);
    vector<pair<pair<int, int>, int>> start_times(n);

    for(int i=0; i<n; ++i) {
        cin >> start_times[i].first.first >> end_times[i].first;
        start_times[i].first.second = end_times[i].first;
        start_times[i].second = i;
        end_times[i].second = i;
    }
    
    set<int> rooms;
    for(int i=1; i<=n; ++i) {
        rooms.insert(i);
    }

    map<int, vector<int>> used;
    sort(start_times.begin(), start_times.end());
    sort(end_times.begin(), end_times.end());
    vector<int> soln(n, -1);
    int left = 0, right = 0;
    while(left < n) {
        if(start_times[left].first.first <= end_times[right].first) {
            used[start_times[left].first.second].push_back(*rooms.begin());
            soln[start_times[left].second] = *rooms.begin();
            rooms.erase(rooms.begin()); 
            ++left;
        } else {
            rooms.insert(used[end_times[right].first].back());
            used[end_times[right].first].pop_back();
            ++right;
        }
    }
    cout << *max_element(soln.begin(), soln.end()) << endl;
    for(int i=0; i<n; ++i) {
        cout << soln[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}