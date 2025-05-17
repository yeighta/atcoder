# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    long long H, W;
    cin >> H >> W;

    long long ans = 0;

    if (H == 1 || W == 1) {
        ans = 1;
    } else if (H % 2 == 0) {
        ans = W * H / 2;
    }
    else {
        ans = W * (H - 1) / 2 + (W + 1) / 2;
    }

    cout << ans << endl;
}
