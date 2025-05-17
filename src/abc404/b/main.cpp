# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    vector<string> T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<string> S_rotated_90(N, string(N, ' '));
    vector<string> S_rotated_180(N, string(N, ' '));
    vector<string> S_rotated_270(N, string(N, ' '));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S_rotated_90[j][N - i - 1] = S[i][j];
            S_rotated_180[N - i - 1][N - j - 1] = S[i][j];
            S_rotated_270[N - j - 1][i] = S[i][j];
        }
    }
    
    int ans = 1000000000;

    int S_diff = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] != T[i][j]) {
                S_diff++;
            }
        }
    }

    ans = min(ans, S_diff);

    S_diff = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S_rotated_90[i][j] != T[i][j]) {
                S_diff++;
            }
        }
    }

    ans = min(ans, S_diff);

    S_diff = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S_rotated_180[i][j] != T[i][j]) {
                S_diff++;
            }   
        }
    }

    ans = min(ans, S_diff);

    S_diff = 3;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S_rotated_270[i][j] != T[i][j]) {
                S_diff++;
            }
        }
    }

    ans = min(ans, S_diff);

    cout << ans << endl;
}
