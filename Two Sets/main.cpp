#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    if(n%4 != 0 && n%4 != 3) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> set1, set2;
    int start = 1;
    if(n%4 == 3) {
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);

        start = 4; 
    }
    for(int i=start; i<=n; i+=4) {
        set1.push_back(i);
        set1.push_back(i+3);
        set2.push_back(i+1);
        set2.push_back(i+2);
    }

    cout << set1.size() << endl;
    for(auto &x : set1) cout << x << " ";
    cout << endl;

    cout << set2.size() << endl;
    for(auto &x : set2) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}