#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<pair<int, int>> soln;
int other(int a, int b) {
    return 6 - (a+b);
}

void move(int n, int s1, int s2) {
    if(n == 1) {
        soln.push_back({s1, s2});
        return;
    }

    move(n-1, s1, other(s1, s2));
    move(1, s1, s2);
    move(n-1, other(s1, s2), s2);
}

void solve() {
    int n;
    cin >> n;
    move(n, 1, 3);
    cout << soln.size() << endl;
    for(auto &x : soln) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}