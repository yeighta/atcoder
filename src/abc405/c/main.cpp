# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long ans = 0;
    vector<long long> sum(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        // 累積和を計算
        sum[i] += sum[i - 1] + A[i - 1];
    }

    for (int i = 0; i + 1 < N; i++) {
        ans += A[i] * (sum[N] - sum[i + 1]);
    }

    cout << ans << endl;

    return 0;
}

