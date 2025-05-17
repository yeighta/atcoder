# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, M;
    cin >> N >> M;

    if (N != M) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> graph(N);
    dsu d(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
        d.merge(a, b);
    }

    // 連結の確認
    if (d.size(0) != N) {
        cout << "No" << endl;
        return 0;
    }

    // 各頂点に2つ以上の辺がある場合はNo
    for (int i = 0; i < N; i++) {
        if (graph[i].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}

