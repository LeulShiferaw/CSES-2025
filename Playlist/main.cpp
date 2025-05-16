#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> k(n);
    for(auto &x : k) { 
        cin >> x;
    }

    map<int, int> pos;
    pos[k[0]] = 1;
    int curr_ind = 1, soln = 1;
    for(int i=1; i<n; ++i) {
        if(pos[k[i]] < curr_ind) {
            pos[k[i]] = i+1;
        } else {
            curr_ind = pos[k[i]] + 1;
            pos[k[i]] = i+1;
        }

        soln = max(soln, i+1-curr_ind+1);
    }
    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}