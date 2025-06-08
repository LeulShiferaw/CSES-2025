#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

constexpr int MOD = (int)1e9 + 7;

template <int mod_num>
class ModInt {
    private:
        ll val;
    public:
        ModInt():val(0ll) {}
        ModInt(const ll &v) :val(v) {}
        ModInt& operator+=(const ModInt& mi) {
            this->val += mi.val;
            if(this->val < 0) this->val += mod_num;
            if(this->val >= mod_num) this->val -= mod_num;
            return *this;
        }
        ModInt& operator-=(const ModInt& mi) {
            this->val -= mi.val;
            if(this->val < 0) this->val += mod_num;
            if(this->val >= mod_num) this->val -= mod_num;
            return *this;
        }
        ModInt& operator*=(const ModInt& mi) {
            this->val *= mi.val;
            this->val %= mod_num;
            if(this->val < 0) this->val += mod_num;
            return *this;
        }
        ModInt operator+(const ModInt &mi) {
            auto res = ModInt();
            res = *this;
            res += mi;
            return res;
        }
        ModInt operator-(const ModInt &mi) {
            auto res = ModInt();
            res = *this;
            res -= mi;
            return res;
        }
        ModInt operator*(const ModInt &mi) {
            auto res = ModInt();
            res = *this;
            res *= mi;
            return res;
        }
        ll getVal() {
            return val;
        }
        void setVal(const ll &v) {
            val = v;
        }
};

void solve() {
    int t;
    cin >> t;

    vector<ModInt<MOD>> soln(4);
    vector<ll> res(1000000+1, 0);
    soln[2].setVal(1);
    for(int i=1; i<=1000000; ++i) {
        vector<ModInt<MOD>> new_soln(4);
        new_soln[0] += soln[0];
        new_soln[0] += soln[2];
        new_soln[0] += soln[3];

        new_soln[1] += soln[1];
        new_soln[1] += soln[2];
        new_soln[1] += soln[3];

        new_soln[2] += soln[0];
        new_soln[2] += soln[2];
        new_soln[2] += soln[3];
            
        new_soln[3] += soln[1];
        new_soln[3] += soln[2];
        new_soln[3] += soln[3];
        swap(new_soln, soln);
        soln[1] *= 3;

        ModInt<MOD> tmp;
        tmp += soln[2];
        tmp += soln[3];
        res[i] = tmp.getVal();
    }

    while(t--) {
        int n;
        cin >> n;

        cout << res[n] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}