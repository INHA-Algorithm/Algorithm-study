#include <bits/stdc++.h>

using namespace std;

#define MAX 500
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct effect {
    int dir;
    int cnt;
    int ratio;
};
effect effects[] = { // 바람 방향에 dir 더한 방향으로 cnt 칸 뒤에 ratio 퍼센트 이동
        {0,  2, 5},
        {1,  1, 10},
        {-1, 1, 10},
        {2,  1, 7},
        {-2, 1, 7},
        {2,  2, 2},
        {-2, 2, 2},
        {3,  1, 1},
        {-3, 1, 1}
};

bool chk[MAX][MAX];
int graph[MAX][MAX];

int n;
int ans;
struct cmd {
    int dir;
    int r;
    int c;
};

bool oob(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

int mkdir(int v) {
    v %= 8;
    return v < 0 ? v + 8 : v;
}

void hit(int dir, int r, int c) {
    int sand = graph[r][c];
    graph[r][c] -= sand;
    int a = sand;
    for (effect e: effects) {
        int nd = mkdir(dir + e.dir);
        int nr = r + (dr[nd] * e.cnt);
        int nc = c + (dc[nd] * e.cnt);
        int v = (sand * e.ratio) / 100;
        a -= v;
        if (oob(nr, nc)) {
            ans += v;
            continue;
        }
        graph[nr][nc] += v;
    }
    int ar = r + dr[dir];
    int ac = c + dc[dir];
    if (oob(ar, ac)) {
        ans += a;
        return;
    }
    graph[ar][ac] += a;
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
}

void solve() {
    cmd cur = {6, n / 2, n / 2};
    chk[cur.r][cur.c] = true;
    while (true) {
        cur = {cur.dir,
               cur.r + dr[cur.dir],
               cur.c + dc[cur.dir]
        };
        if(oob(cur.r, cur.c)) break;
        hit(cur.dir, cur.r, cur.c);
        chk[cur.r][cur.c] = true;

        int nd = mkdir(cur.dir - 2);
        int nr = cur.r + dr[nd];
        int nc = cur.c + dc[nd];
        if (!chk[nr][nc]) {
            cur.dir = nd;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
