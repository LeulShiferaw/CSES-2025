#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    int curr_a = 0, curr_b = 0;
    while(curr_a < (int)a.size() && curr_b < (int)b.size()) {
        if(b[curr_b] < (a[curr_a]-k)) {
            ++curr_b;
        } else if(b[curr_b] > (a[curr_a]+k)) {
            ++curr_a;
        } else {
            ++res;
            ++curr_a;
            ++curr_b;
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