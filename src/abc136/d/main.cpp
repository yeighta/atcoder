#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    string S;
    cin >> S;


    vector<int> LR;
    vector<int> RL;
    for (int i = 0; i < S.size(); i++) {
        // 次の文字と比較
        // LR のLインデックスを取得
        if (S[i] == 'L' && S[i + 1] == 'R') {
            LR.push_back(i);
        }
        // RL のRインデックスを取得
        if (S[i] == 'R' && S[i + 1] == 'L') {
            RL.push_back(i);
        }
    }

    vector<int> ans(S.size(), 0);
    vector<vector<int>> group;

    // グループごとに計算
    for (int i = 0; i < LR.size(); i++) {
        // グループの左端と右端を取得
        if (i == 0) {
            group.push_back({0, LR[i]});
        } 
        else {
            group.push_back({LR[i - 1] + 1, LR[i]});
        }

        // 最終グループであれば末尾のグループも足す
        if (i == LR.size() - 1) {
            group.push_back({LR[i] + 1, static_cast<int>(S.size()) - 1});
        }
    }

    if (LR.size() == 0) {
        group.push_back({0, static_cast<int>(S.size()) - 1});
    }

    for (int i = 0; i < group.size(); i++) {
        int group_start = group[i][0];
        int group_end = group[i][1];

        // グループ内の RL を探索
        int group_RL;
        for (int j = group_start; j <= group_end; j++) {
            for (int k = 0; k < RL.size(); k++) {
                if (RL[k] == j) {
                    // RL を見つけた
                    group_RL = RL[k];
                    break;
                }
            }
        }

        for (int j = group_start; j <= group_end; j++) {
            // Rとの距離が偶数であればその位置に+
            if (abs(group_RL - j) % 2 == 0) {
                // 偶数
                ans[group_RL] ++;
            } else {
                // 奇数
                ans[group_RL + 1] ++;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
