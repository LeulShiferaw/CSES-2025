#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string str;
    cin >> str;

    sort(str.begin(), str.end());

    vector<string> res;
    do {
        res.push_back(str);  
    } while(next_permutation(str.begin(), str.end()));

    cout << res.size() << endl;
    for(auto &x : res) cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}