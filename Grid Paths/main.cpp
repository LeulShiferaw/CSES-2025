#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string path = "";
    cin >> path;

    auto res = 0;

    constexpr int N = 7;
    constexpr int SIZE = N*N-1;
    vector<vector<bool>> used(N, vector<bool>(N, false));
    auto correct = [&](int x, int y) {
        if(x < 0 || x >= N || y < 0 || y >= N) return false;
        if(used[x][y]) return false;
        return true;
    };

    function<void(int, int, int)> calcPaths = [&](int x, int y, int ind) {
        if((x == (N-1)) && (y == 0)) {
            if(ind == SIZE) {
                ++res;
                return;
            }
            return;
        }

        if(ind == SIZE) return;


        if(path[ind] == '?') {
            if(correct(x+1, y)) {
                if(correct(x+2, y) || !correct(x+1, y-1) || !correct(x+1, y+1)) {
                    used[x][y] = true;
                    calcPaths(x+1, y, ind+1);
                    used[x][y] = false;
                }
            } 
            if(correct(x-1, y)) {
                if(correct(x-2, y) || !correct(x-1, y-1) || !correct(x-1, y+1)) {
                    used[x][y] = true;
                    calcPaths(x-1, y, ind+1);
                    used[x][y] = false;
                }
            } 
            if(correct(x, y+1)) {
                if(correct(x, y+2) || !correct(x-1, y+1) || !correct(x+1, y+1)) {
                    used[x][y] = true;
                    calcPaths(x, y+1, ind+1);
                    used[x][y] = false;
                }
            }  
            if(correct(x, y-1)) {
                if(correct(x, y-2) || !correct(x-1, y-1) || !correct(x+1, y-1)) {
                    used[x][y] = true;
                    calcPaths(x, y-1, ind+1);
                    used[x][y] = false;
                }
            }
        } else if (path[ind] == 'R') {
            if(correct(x, y+1)) {
                if(correct(x, y+2) || !correct(x-1, y+1) || !correct(x+1, y+1)) {
                    used[x][y] = true;
                    calcPaths(x, y+1, ind+1);
                    used[x][y] = false;
                }
            }  
        } else if (path[ind] == 'L') {
            if(correct(x, y-1)) {
                if(correct(x, y-2) || !correct(x-1, y-1) || !correct(x+1, y-1)) {
                    used[x][y] = true;
                    calcPaths(x, y-1, ind+1);
                    used[x][y] = false;
                }
            }
        } else if(path[ind] == 'D') {
            if(correct(x+1, y)) {
                if(correct(x+2, y) || !correct(x+1, y-1) || !correct(x+1, y+1)) {
                    used[x][y] = true;
                    calcPaths(x+1, y, ind+1);
                    used[x][y] = false;
                }
            }
        } else if(path[ind] == 'U') {
            if(correct(x-1, y)) {
                if(correct(x-2, y) || !correct(x-1, y-1) || !correct(x-1, y+1)) {
                    used[x][y] = true;
                    calcPaths(x-1, y, ind+1);
                    used[x][y] = false;
                }
            }
        }
    };

    calcPaths(0, 0, 0);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}