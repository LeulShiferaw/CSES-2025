#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    vector<int> ind(n);
    int mn = INT_MAX, mx = INT_MIN;
    for(int i=0; i<n; ++i) {
        cin >> x[i];
        ind[x[i]] = i;
        mn = min(mn, x[i]);
        mx = max(mx, x[i]);
    }

    ind[mn - 1] = -1; //Because we will do x[i]-1 and x[i]+1 we need to make sure they are out of range
    ind[mx + 1] = -1;

    vector<pair<int, int>> swap_pos(m);
    for(int i=0; i<m; ++i) {
        cin >> swap_pos[i].first >> swap_pos[i].second;
    }

    int curr_pos = ind[1];
    int rounds = 1;
    for(int i=2; i<=n; ++i) {
        if(curr_pos > ind[i]) {
            ++rounds;
        }
        curr_pos = ind[i];
    }

    for(int i=0; i<m; ++i) {
        int a = swap_pos[i].first-1;
        int b = swap_pos[i].second-1;

        if(a > b) swap(a, b); //make sure that a is less than b

        //Move a to before b
        if((ind[x[a]-1] > a) && (ind[x[a]-1] < b)) {
            --rounds; //Decrement because x[a]-1 is going to be passed on our way to b. Thefore decreasing the time
        }
        if((ind[x[a]+1] > a) && (ind[x[a]+1] < b)) {
            ++rounds;
        }

        //Move b to a
        if((ind[x[b]-1] >= a) && (ind[x[b]-1] < b)) {
            ++rounds;
        }
        if((ind[x[b]+1]) >= a && (ind[x[b]+1] < b)) {
            --rounds;
        }
        
        cout << rounds << endl;

        //Do the swap
        swap(ind[x[a]], ind[x[b]]);
        swap(x[a], x[b]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}