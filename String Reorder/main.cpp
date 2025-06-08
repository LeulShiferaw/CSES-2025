#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve() {
    multiset<char> letters;
    string str;
    cin >> str;

    for(auto &c : str) {
        letters.insert(c);
    }

    string res = "";
    res.push_back('a');
    res.push_back(*letters.begin());
    letters.erase(letters.begin());

    while(letters.size() > 0) {
        char first = *letters.begin();
        if(first == res.back()) {
            auto greater = letters.upper_bound(res.back());
            if(greater == letters.end()) {
                set<int> pos;
                for(int i=res.size()-1; i>=0; --i) {
                    if(res[i] == first) --i;
                    else {
                        pos.insert(i);
                        if(pos.size() == letters.size()) break;
                    }
                }
                if(pos.size() != letters.size()) {
                    cout << -1 << endl;
                    return;
                } else {
                    string new_res = "";
                    for(int i=0; i<(int)res.size(); ++i) {
                        new_res.push_back(res[i]);
                        if(pos.find(i) != pos.end()) {
                            new_res.push_back(first);
                        }
                    }

                    swap(res, new_res);
                    break;
                }
            } else {
                res.push_back(*greater);
                letters.erase(greater);
            }
        } else {
            res.push_back(first);
            letters.erase(letters.begin());
        }
    }
    cout << res.substr(1, res.size()-1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}