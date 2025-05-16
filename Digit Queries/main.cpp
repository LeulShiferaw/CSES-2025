#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int q;
    cin >> q;

    while(q--) {
        ll k;
        cin >> k;

        //Get the number of digits that it should have
        //Remove from k
        //Example if the answer is the 4 in 1234 we would get that it has 4 digits
        //offset would also start from beginning of 1000, 1001 instead of 1234...
        int num_dig = 0;
        for(int i=1; ;++i) {
            k -= i*9ll*(ll)pow(10, i-1); //amount of characters with i number of digits

            if(k <= 0) {
                k += i*9ll*(ll)pow(10, i-1);
                num_dig = i;
                break;
            }
        }

        //We know that it as num_dig  number of digits in the answer (the number it is located in)
        //Now find what the first digit is, the second, third ...
        //Keep subtracting from the offset
        //In the end we should have the exact number it is in.
        //Now we should be able to convert it to string and use the offset directly
        ll num = 0;
        for(int i=1; i<=num_dig; ++i) {
            int start = 0;
            if(i == 1) start = 1;
            int curr_dig = 0;
            for(int j=start; j<=9; ++j) {
                k -= num_dig * (ll)pow(10, num_dig - i); //amount of characters with j in the ithe character and num_dig number of characters

                if(k <= 0) {
                    k += num_dig * (ll)pow(10, num_dig - i);
                    curr_dig = j;
                    break;
                }
            }

            num *= 10;
            num += curr_dig;
        }

        cout << to_string(num)[k-1] << endl; //k is offset in number num
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}