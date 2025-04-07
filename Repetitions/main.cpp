#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string dna;
    cin >> dna;

    int curr = 1;
    int soln = 1;
    for(int i=1; i<(int)dna.size(); ++i) {
        if(dna[i-1] == dna[i]) {
            ++curr;
            soln = max(curr, soln);
        } else {
            soln = max(soln, curr);
            curr = 1;
        }
    }

    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}