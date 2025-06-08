#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


namespace funcs {
    auto sum = [](const ll&a, const ll&b) {
        return a+b;
    };

    auto Xor = [](const ll&a, const ll&b) {
        return a xor b;
    };

    auto Max = [](const ll &a, const ll &b) {
        return max(a, b);
    };

    auto Min = [](const ll &a, const ll &b) {
        return min(a, b);
    };
};

class SegTree {
    private:
        int base; ll initial;
        vector<ll> seg_tree; 
        function<ll(ll, ll)> func;
    public:
        SegTree(const vector<ll> &in, const function<ll(ll, ll)> &cmp_func, const ll &init) :initial(init), func(cmp_func){
            int n = in.size();
            int maxLog = ceil(log2(n));
            base = 1 << maxLog;
            seg_tree.resize(2*base, initial);
            
            for(int i=0; i<n; ++i) seg_tree[i+base] = in[i];
            for(int i=base-1; i>=1; --i) seg_tree[i] = func(seg_tree[2*i], seg_tree[2*i+1]);
        }

        ll sum(int a, int b) {
            --a; --b;
            a += base; b += base;

            ll res = initial;
            while(a <= b) {
                if(a%2 == 1) res = func(res, seg_tree[a++]);
                if(b%2 == 0) res = func(res, seg_tree[b--]);
                
                a/=2;
                b/=2;
            }

            return res;
        }

        void set(int k, int x) {
            k--;
            k += base;
            seg_tree[k] = x;
            for(k/=2; k>=1; k/=2) {
                seg_tree[k] = func(seg_tree[2*k], seg_tree[2*k+1]);
            }   
        }

        void add(int k, int x) {
            k--;
            k += base;
            seg_tree[k] += x;
            for(k/=2; k>=1; k/=2) {
                seg_tree[k] = func(seg_tree[2*k], seg_tree[2*k+1]);
            }
        } 
};

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n);
    for(auto &z : x) cin >> z;

    vector<ll> sums;
    ll curr_sum = 0;
    for(auto &z : x) {
        curr_sum += z;
        sums.push_back(curr_sum);
    }

    SegTree mytree(sums, funcs::Min, LLONG_MAX);
    ll soln = sums[a-1];
    for(int i=a; i<n; ++i) {
        auto tmp = mytree.sum(max(1, i-b+1), i-a+1);
        if(i-b+1 < 1) {
            tmp = min(tmp, 0ll);
        }
        soln = max(soln, sums[i]-tmp);
    }
    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}