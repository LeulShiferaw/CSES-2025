#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) n/=2;
        else n = 3*n + 1;
    }
    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}