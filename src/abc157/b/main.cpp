# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    vector<vector<int>> A(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    int N;
    cin >> N;

    vector<int> B(N);    
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<vector<bool>> bingo(3, vector<bool>(3, false));

    // 一致判定
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (A[j][k] == B[i]) {
                    bingo[j][k] = true;
                }
            }
        }
    }

    // ビンゴ判定
    for (int i = 0; i < 3; i++) {
        if (bingo[i][0] && bingo[i][1] && bingo[i][2]) {
            cout << "Yes" << endl;
            return 0;
        }
        if (bingo[0][i] && bingo[1][i] && bingo[2][i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    if (bingo[0][0] && bingo[1][1] && bingo[2][2]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (bingo[0][2] && bingo[1][1] && bingo[2][0]) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
