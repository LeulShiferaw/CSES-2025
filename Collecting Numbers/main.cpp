#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    map<int, int> ind;
    for(int i=0; i<n; ++i) {
        cin >> x[i];
        ind[x[i]] = i;
    }

    int curr_pos = ind[1];
    int rounds = 1;
    for(int i=2; i<=n; ++i) {
        if(curr_pos > ind[i]) {
            ++rounds;
        }
        curr_pos = ind[i];
    }
    cout << rounds << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}