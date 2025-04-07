#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string str;
    cin >> str;

    sort(str.begin(), str.end());

    map<char, int> cnt;
    for(auto &ch : str) {
        cnt[ch]++;
    }

    int cnt_odd = 0;
    pair<char, int> odd_val = {'a', 0};
    for(auto &val : cnt) {
        if(val.second % 2 == 1) {
            odd_val = val;
            ++cnt_odd;
        }
    }

    if(cnt_odd > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    if(odd_val.second != 0) {
        cnt[odd_val.first] = 0;
    }

    string res = "";
    for(auto &val : cnt) {
        for(int i=0; i<val.second/2; ++i) {
            res.push_back(val.first);
        } 
    }

    for(int i=0; i<odd_val.second; ++i) {
        res.push_back(odd_val.first);
    }

    for(auto itr = cnt.rbegin(); itr != cnt.rend(); ++itr) {
        for(int i=0; i<itr->second/2; ++i) {
            res.push_back(itr->first);
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}