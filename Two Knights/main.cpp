#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    vector<ll> ans;
    ans.push_back(-1);
    ans.push_back(0);
    ans.push_back(6);
    ans.push_back(28);
    ans.push_back(96);

    if(n <= 4) {
        for(int i=1; i<=n; ++i) cout << ans[i] << endl;
        return;
    }

    for(int i=1; i<=4; ++i) {
        cout << ans[i] << endl;
    }

    for(ll i=5; i<=n; ++i) {
        //First 3 expressions are for picking one knight on the new row or col and the rest are for picking two knights on the new rol and col. 
        //For the second part just do choose 2 and subtract the wrong chooses (which is just 2)
        ans.push_back(ans.back() + 2*(i-5)*((i-1)*(i-1) - 4) + 5*((i-1)*(i-1) - 2) + 4*((i-1)*(i-1) - 3) + ((2*i-1)*(2*i-2))/2 - 2);
        cout << ans.back() << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}