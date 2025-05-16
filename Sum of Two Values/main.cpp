#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    int l = 0, r = a.size()-1;
    while(l < r) {
        ll curr_sum = a[l].first + a[r].first;
        if(curr_sum == x) {
            cout << a[l].second << " " << a[r].second << endl;
            return;
        } else if(curr_sum > x) {
            --r;
        } else ++l;
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}