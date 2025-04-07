#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << n << endl;
        return;
    } else if(n <=3) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    for(int i=2; i<=n; i+=2) {
        cout << i << " ";
    }

    for(int i=1; i<=n; i+=2) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}