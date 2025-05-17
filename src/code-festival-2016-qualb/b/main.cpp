# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, A, B;
    string C;

    cin >> N >> A >> B;
    cin >> C;

    vector<string> ans(N);
    int passed_all = 0;
    int overseas_rank = 1;
    for (int i = 0; i < N; i++) {
        if (C[i] == 'c') {
            ans[i] = "No";
        }
        else if (C[i] == 'a') {
            if (passed_all < A + B) {
                ans[i] = "Yes";
                passed_all++;
            }
            else {
                ans[i] = "No";
            }
        } else if (C[i] == 'b') {
            if(passed_all < A + B) {
                if (overseas_rank <= B) {
                    ans[i] = "Yes";
                    passed_all++;
                    overseas_rank++;
                } else {
                    ans[i] = "No";
                    overseas_rank++;
                }
            } else {
                ans[i] = "No";
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
