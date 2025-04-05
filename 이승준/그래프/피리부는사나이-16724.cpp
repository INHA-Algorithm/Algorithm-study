#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>
#include<cstring>

using namespace std;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 1001

int n, m, cnt, turn;
char board[MAX][MAX];
bool visited[MAX][MAX];
int seen[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

// U R L D
void input();

void solve();

int main() {
    fastio();
    input();
    solve();
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
}

int getDir(int y, int x) {
    for (int i = 0; i < 4; i++) {
        if (dir[i] == board[y][x]) {
            return i;
        }
    }
    return -1;
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;
    seen[start.first][start.second] = turn;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        int d = getDir(y, x);
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (seen[ny][nx] == turn) {
            // Cycle 탐지 -> SAFE ZONE 증가
            cnt++;
            return;
        }

        if (!visited[ny][nx]) {
            visited[ny][nx] = true;
            seen[ny][nx] = turn;
            q.push({ny, nx});
        }


    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                turn++;
                bfs({i, j});
            }
        }
    }
    cout << cnt;
}