# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= N; i++) {
        // 末尾を消した部分列
        vector<int> B(N);
        B = A;

        for (int j = 0; j < i; j++) {
            B.pop_back();
        }

        vector<int> memo(M, 0);
        for (int j = 0; j < B.size(); j++) {
            memo[B[j] - 1]++;
        }

        bool flag = true;
        for (int j = 0; j < M; j++) {
            if (memo[j] == 0) {
                flag = false;
            }
        }

        if (!flag) {
            cout << i << endl;
            return 0;
        }
    }
}
