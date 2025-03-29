#include <bits/stdc++.h>

using namespace std;

int rd[4] = {1, 0, -1, 0};
int cd[4] = {0, 1, 0, -1};

struct Node {
    int r, c;
    int cnt;
    int d;
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.cnt > b.cnt;
    }
};

bool chk[51][51];
int house[51][51]; // -1: 벽, 0 : 공간, 1 : 거울 가능
int n;
Node src;
Node dst;

bool oob(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

bool isWall(int r, int c) {
    return (house[r][c] == -1);
}

void init() {
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            char c = input[j];
            if (c == '*') {
                house[i][j] = -1;
                continue;
            }
            if (c == '#') {
                if (flag) {
                    src = {i, j, 0};
                    flag = false;
                } else dst = {i, j, 2501};
                continue;
            }
            if (c == '!') {
                house[i][j] = 1;
                continue;
            }
        }
    }

}


void solve() {
    priority_queue<Node, vector<Node>, cmp> q;
    for (int i = 0; i < 4; i++) {
        int nr = src.r + rd[i];
        int nc = src.c + cd[i];
        if (oob(nr, nc))continue;
        if (isWall(nr, nc))continue;
        q.push({nr, nc, src.cnt, i});
    }

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();


        if (cur.r == dst.r && cur.c == dst.c) {
            dst.cnt = min(dst.cnt, cur.cnt);
            continue;
        }
        if (chk[cur.r][cur.c])continue;

        if (house[cur.r][cur.c]) {
            for (int i = 1; i < 4; i += 2) {
                int nd = (cur.d + i) % 4;
                int nr = cur.r + rd[nd];
                int nc = cur.c + cd[nd];
                if (oob(nr, nc))continue;
                if (isWall(nr, nc))continue;
                q.push({nr, nc, cur.cnt + 1, nd});
            }
            chk[cur.r][cur.c] = true;
        }
        int nr = cur.r + rd[cur.d];
        int nc = cur.c + cd[cur.d];
        if (oob(nr, nc))continue;
        if (isWall(nr, nc))continue;
        q.push({nr, nc, cur.cnt, cur.d});
    }

    cout << dst.cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
