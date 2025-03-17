#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int N, M, K;
int rd[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cd[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int mod(int x) {
    int y = x % N;
    return y < 0 ? y + N : y;
}

struct fb {
    int dir;
    int mass;
    int speed;
};


struct node {
    queue<fb> readyQ;
    vector<fb> arrived;
};

node graph[MAX][MAX];

void shoot(int r, int c) {
    queue<fb>*q = &graph[r][c].readyQ;
    while (!q->empty()) {
        fb cur = q->front();
        q->pop();
        int nr = mod(r + (rd[cur.dir] * cur.speed));
        int nc = mod(c + (cd[cur.dir] * cur.speed));
        graph[nr][nc].arrived.push_back(cur);
    }
}

void split(int r, int c) {
    vector<fb>* v = &graph[r][c].arrived;
    queue<fb>*q = &graph[r][c].readyQ;
    if (v->empty())return;
    if (v->size() == 1) {
        q->push(graph[r][c].arrived[0]);
        v->clear();
        return;
    }
    int m = 0, s = 0, dir = 0;
    bool flag = v->front().dir % 2;
    for (fb cur: *v) {
        m += cur.mass;
        s += cur.speed;
        dir |= (flag ^ (cur.dir % 2));
    }
    m /= 5;
    s /= v->size();
    v->clear();
    if (!m)return;

    for (int d = dir; d < 8; d += 2) {
        q->push({d, m, s});
    }
}

int count() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (!graph[i][j].readyQ.empty()) {
                ret += graph[i][j].readyQ.front().mass;
                graph[i][j].readyQ.pop();
            }
        }
    }
    return ret;
}

void init() {
    cin >> N >> M >> K;
    while (M--) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        graph[r - 1][c - 1].readyQ.push({d, m, s});
    }
}

void solve() {
    while (K--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                shoot(i, j);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                split(i, j);
            }
        }
    }
    cout << count();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}