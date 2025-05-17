# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += min(A[i], K - A[i]);
    }

    cout << 2 * sum << endl;
}
