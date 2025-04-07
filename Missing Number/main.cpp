#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    long long sum = 0;
    for(int i=0; i<n-1; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << (ll)n*(n+1ll)/2ll - sum << endl;


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}