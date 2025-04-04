#include <bits/stdc++.h>

#define MAX 1001
using namespace std;

// U,D,L,R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int graph[MAX][MAX];
int mem[MAX][MAX];
int cnt;
int n, m;

int dfs(int r, int c) {
    if (mem[r][c] == -1) {
        return mem[r][c] = ++cnt;
    }
    if (mem[r][c]) return mem[r][c];

    mem[r][c] = -1;
    int dir = graph[r][c];
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    return mem[r][c] = dfs(nr, nc);
}


void init() {
    cin >> n >> m;
    for (int r = 0; r < n; r++) {
        string input;
        cin >> input;
        for (int c = 0; c < m; c++) {
            char in = input[c];
            if (in == 'U') {
                graph[r][c] = 0;
            } else if (in == 'D') {
                graph[r][c] = 1;
            } else if (in == 'L') {
                graph[r][c] = 2;
            } else {
                graph[r][c] = 3;
            }
        }
    }
}

void solve() {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (!mem[r][c]) dfs(r, c);
        }
    }
    cout << cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
