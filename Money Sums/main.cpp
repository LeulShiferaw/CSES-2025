#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int n;
    cin >> n;
    
    int sum = 0;
    vector<int> x(n);
    for(auto &z : x) {
        cin >> z;
        sum += z;
    }

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for(int i=0; i<n; ++i) {
        for(int j = sum - x[i]; j>=0; --j) {
            dp[j+x[i]] = dp[j+x[i]] | dp[j];
        }
    }

    int res = 0;
    vector<int> nums;
    for(int i=1; i<=sum; ++i) {
        res += (dp[i] == true ? 1 : 0);
        if(dp[i]) nums.push_back(i);
    }
    cout << res << endl;

    for(auto &x : nums) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}