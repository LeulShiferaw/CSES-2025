#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

constexpr int MOD = (int)1e9 + 7;

ll exp(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;

    if(b%2 == 0) {
        ll temp = exp(a, b/2);
        return (temp * temp) % MOD;
    }
    else return (a*exp(a, b-1)) % MOD;
}

ll exp2(int a, long long b) {
    if(b < MOD) return exp(a, b);
    return exp(a, b % (MOD-1));
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(auto &z : x) cin >> z;

    auto inv_mod = [&](const ll &a) {
        return exp2(a, MOD-2);        
    };

    map<int, int> cnt;
    ll total = 0;

    /*
    Formula: total += ((total-cnt[k])/(cnt[k]+1)) + 1;
    This is because we first remove all sequences that just contain k. That is k.
    Because there are only cnt[k] elements that are only k because only cnt[k] elements are in the array so far.
    
    Then, we can imagine if there are (for example) 3 elements that are k that come before the current number, we must divide the number of elements by cnt[k]+1.
    This is because: lets say that the section of subsets that don't contain any k are q. Then there will be 3 more sections like that each containing one more k.
    */
    for(auto &k : x) {
        ll tmp = total - cnt[k];
        tmp %= MOD;
        if(tmp < 0) tmp += MOD;
        tmp *= inv_mod(cnt[k]+1);
        tmp %= MOD;
        if(tmp < 0) tmp += MOD;
        total += tmp + 1;
        total %= MOD;
        if(total < 0) total += MOD;

        //total += ((total-cnt[k])/(cnt[k]+1)) + 1; The one above is this formula but with inverser mode instead of just dividing
        cnt[k]++;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}