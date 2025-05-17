# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    for (int h = 0; h < H; ++h) cin >> field[h];


    vector<pair<int, int>> goal;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (field[h][w] == 'E') {
                goal.push_back({h, w});
            }
        }
    }


    vector<vector<int>> dist_min(H, vector<int>(W, 100));
    vector<vector<int>> prev_x_min(H, vector<int>(W, -1));
    vector<vector<int>> prev_y_min(H, vector<int>(W, -1));

    for (auto g : goal) {
        int sx, sy;
        sx = g.first;
        sy = g.second;

        // 各セルの最短距離 (訪れていないところは -1 としておく)
        vector<vector<int>> dist(H, vector<int>(W, -1));
        dist[sx][sy] = 0; // スタートを 0 に
        // 探索中に各マスはどのマスから来たのかを表す配列 (最短経路長を知るだけなら、これは不要)
        vector<vector<int>> prev_x(H, vector<int>(W, -1));
        vector<vector<int>> prev_y(H, vector<int>(W, -1));

        // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
        queue<pair<int, int> > que;
        que.push(make_pair(sx, sy)); // スタートを push

        while (!que.empty()) {
            pair<int, int> current_pos = que.front(); // キューの先頭を見る (C++ ではこれをしても pop しない)
            int x = current_pos.first;
            int y = current_pos.second;
            que.pop(); // キューから pop を忘れずに

            // 隣接頂点を探索
            for (int direction = 0; direction < 4; ++direction) {
                int next_x = x + dx[direction];
                int next_y = y + dy[direction];
                if (next_x < 0 || next_x >= W || next_y < 0 || next_y >= H) continue; // 場外アウトならダメ
                if (field[next_x][next_y] == '#') continue; // 壁はダメ

                // まだ見ていない頂点なら push
                if (dist[next_x][next_y] == -1) {
                    que.push(make_pair(next_x, next_y));
                    dist[next_x][next_y] = dist[x][y] + 1;
                    prev_x[next_x][next_y] = x;  // どの頂点から情報が伝播して来たか、縦方向の座標をメモ
                    prev_y[next_x][next_y] = y;  // どの頂点から情報が伝播して来たか、横方向の座標をメモ
                }
            }
        }

        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (dist_min[h][w] <= dist[h][w]) {
                    continue;
                } else {
                    dist_min[h][w] = dist[h][w];
                    prev_x_min[h][w] = prev_x[h][w];
                    prev_y_min[h][w] = prev_y[h][w];
                }
            }
        }
    }
    
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (field[h][w] != '.') cout << field[h][w];
            else cout<< dist_min[h][w];
        }
        cout << endl;
    }
}
