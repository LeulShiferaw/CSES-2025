#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<string> codes;
    codes.push_back("0");
    codes.push_back("1");
    
    for(int c=2; c<=n; ++c) {
        int sz = codes.size();
        for(int i=0; i<sz; ++i) {
            codes[i] = "0" + codes[i];
        }

        for(int i=sz-1; i>=0; --i) {
            codes.push_back(codes[i]);
            codes.back()[0] = '1';
        }
    }

    for(auto &x : codes) {
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}