#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) x.begin(),x.end()
using ll = long long;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*
BFS instead of DFS
*/

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> moves(n, vector<int>(n, 1000001));
    vector<vector<bool>> used(n, vector<bool>(n, false));
    queue<pair<int, int>> pos;
    moves[0][0] = 0;
    auto ok_move = [&](int x, int y) {
        if(x >= 0 && x < n && y >= 0 && y < n && !used[x][y]) return true;
        return false;
    };

    function<void()> calc_min_moves = [&]() {
        pos.push({0, 0});
        while(pos.size() > 0) {
            auto x = pos.front().first;
            auto y = pos.front().second;
            pos.pop();
            vector<pair<int, int>> tmp;
            if(ok_move(x-1, y+2)) tmp.push_back({x-1, y+2}); 
            if(ok_move(x+1, y+2)) tmp.push_back({x+1, y+2}); 
            if(ok_move(x-1, y-2)) tmp.push_back({x-1, y-2}); 
            if(ok_move(x+1, y-2)) tmp.push_back({x+1, y-2}); 
            if(ok_move(x-2, y+1)) tmp.push_back({x-2, y+1}); 
            if(ok_move(x-2, y-1)) tmp.push_back({x-2, y-1}); 
            if(ok_move(x+2, y+1)) tmp.push_back({x+2, y+1}); 
            if(ok_move(x+2, y-1)) tmp.push_back({x+2, y-1});
            for(auto &z : tmp) {
                if(moves[z.first][z.second] > (moves[x][y] + 1)) {
                    moves[z.first][z.second] = moves[x][y] + 1;
                    pos.push(z);
                }
            }
            used[x][y] = true;
        }
    };

    calc_min_moves();
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << moves[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}