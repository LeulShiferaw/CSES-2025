#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> times(n);
    for(auto &x : times) cin >> x.first >> x.second;

    sort(times.begin(), times.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    });

    int prev_end = -1, res = 0;
    for(int i=0; i<n; ++i) {
        if(times[i].first >= prev_end) {
            ++res;
            prev_end = times[i].second;
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