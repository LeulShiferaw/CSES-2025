#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
using ll = long long;

int mymex(vector<int> &vec) {
    sort(all(vec));
    int curr = 0;
    for(int i=0; i<(int)vec.size(); ++i) {
        if(vec[i] > curr) {
            return curr;
        } else if(vec[i] == curr) curr++;
    }
    return curr;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            vector<int> elements;
            for(int k=0; k<j; ++k) elements.push_back(grid[i][k]);
            for(int k=0; k<i; ++k) elements.push_back(grid[k][j]);
            grid[i][j] = mymex(elements);
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n ;++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}