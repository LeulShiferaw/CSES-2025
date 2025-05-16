#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> start_times(n);
    vector<int> end_times(n);
    for(int i=0; i<n; ++i) {
        cin >> start_times[i];
        cin >> end_times[i];
    }

    sort(start_times.begin(), start_times.end());
    sort(end_times.begin(), end_times.end());

    int l=0, r=0;
    int res = 0;
    int soln = 0;
    while(l < n && r < n) {
        if(start_times[l] < end_times[r]) {
            ++res;
            ++l;
        } else {
            --res;
            ++r;
        }

        soln = max(soln, res);
    }

    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}