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

    vector<string> grid(n, "");
    for(int i=0; i<n; ++i) {
        cin >> grid[i];
    }

    deque<vector<int>> chars;
    vector<vector<bool>> used(n, vector<bool>(n, false));
    chars.push_back({0, 0, 0});
    string res = "";
    while(chars.size() > 0) {
        int x = chars.front()[0];
        int y = chars.front()[1];
        int pos = chars.front()[2];
        
        chars.pop_front();

        if(used[x][y]) continue;
        used[x][y] = true;

        if(pos >= (int)res.size()) {
            res.push_back(grid[x][y]);

            if((x+1 < n) && (y+1 < n)) {
                if(grid[x+1][y] < grid[x][y+1]) {
                    chars.push_back({x+1, y, pos+1});
                } else if(grid[x+1][y] > grid[x][y+1]) {
                    chars.push_back({x, y+1, pos+1});
                } else {
                    chars.push_back({x+1, y, pos+1});
                    chars.push_back({x, y+1, pos+1});
                }
            } else if(x+1 < n) {
                chars.push_back({x+1, y, pos+1});
            } else if(y+1 < n) chars.push_back({x, y+1, pos+1});
        } else if(grid[x][y] < res[pos]) {
            res[pos] = grid[x][y];

            deque<vector<int>> tmp;
            while(chars.size() > 0) {
                if(chars.front()[2] == pos) {
                    tmp.push_back(chars.front());
                } else if(chars.front()[2] > pos) break;
                chars.pop_front();
            }
            if((x+1 < n) && (y+1 < n)) {
                if(grid[x+1][y] < grid[x][y+1]) {
                    tmp.push_back({x+1, y, pos+1});
                } else if(grid[x+1][y] > grid[x][y+1]) {
                    tmp.push_back({x, y+1, pos+1});
                } else {
                    tmp.push_back({x+1, y, pos+1});
                    tmp.push_back({x, y+1, pos+1});
                }
            } else if(x+1 < n) {
                tmp.push_back({x+1, y, pos+1});
            } else if(y+1 < n) tmp.push_back({x, y+1, pos+1});

            swap(tmp, chars);
        } else if(grid[x][y] == res[pos]) {
            if((x+1 < n) && (y+1 < n)) {
                if(grid[x+1][y] < grid[x][y+1]) {
                    chars.push_back({x+1, y, pos+1});
                } else if(grid[x+1][y] > grid[x][y+1]) {
                    chars.push_back({x, y+1, pos+1});
                } else {
                    chars.push_back({x+1, y, pos+1});
                    chars.push_back({x, y+1, pos+1});
                }
            } else if(x+1 < n) {
                chars.push_back({x+1, y, pos+1});
            } else if(y+1 < n) chars.push_back({x, y+1, pos+1});
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