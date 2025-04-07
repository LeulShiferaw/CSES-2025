#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &x : arr) cin >> x;

    ll res = 0;
    for(int i=1; i<n; ++i) {
        if(arr[i] < arr[i-1]) {
            res += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
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