#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if((a + b) == 1) {
            cout << "NO" << endl;
            continue;
        }

        if((a+b) == 0) {
            cout << "YES" << endl;
            for(int i=1; i<=n; ++i) cout << i << " ";
            cout << endl;
            for(int i=1; i<=n; ++i) cout << i << " ";
            cout << endl;
            continue;
        }

        //Not possible for one side to always be the greater side
        if(a == 0 || b == 0) {
            cout << "NO" << endl;
            continue;
        }

        //At first bothsides have 1->(a+b)->n
        //If we have like 3 for a then we can shift (a+b), (a+b-1), (a+b-2) to the beginning and keep everything else the same.
        //So just bring the last element to the beginning a times
        if((a+b) <= n) {
            cout << "YES" << endl;

            vector<int> acards, bcards;
            for(int i=(b+1); i<=(a+b); ++i) {
                acards.push_back(i);
            }
            for(int i=1; i<=b; ++i) {
                acards.push_back(i);
            }
            for(int i=(a+b+1); i<=n; ++i) {
                acards.push_back(i);
            }
            for(int i=1; i<=(a+b); ++i) {
                bcards.push_back(i);
            }
            for(int i=(a+b+1); i<=n; ++i) {
                bcards.push_back(i);
            }
            for(auto &x : acards) {
                cout << x << " ";
            }
            cout << endl;

            for(auto &x : bcards) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}