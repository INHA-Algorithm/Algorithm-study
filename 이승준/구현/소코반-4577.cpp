#include <iostream>
using namespace std;

#define MAX 16
#define fastio() cin.tie(0)->sync_with_stdio(0)

char board[MAX][MAX];
bool goal[MAX][MAX];
int n, m, cnt = 0;
pair<int, int> point;
int answer;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void init() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            board[i][j] = '#';
            goal[i][j] = false;
        }
    answer = 0;
    point = {0, 0};
}

bool valid(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

bool isComplete() {
    int bcnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 'B') bcnt++;
    return bcnt == answer;
}

void move(int dir) {
    int y = point.first;
    int x = point.second;
    int ny = y + dy[dir], nx = x + dx[dir];
    if (!valid(ny, nx)) return;

    char next = board[ny][nx];

    if (next == '.' || next == '+') {
        board[ny][nx] = goal[ny][nx] ? 'W' : 'w';
        board[y][x] = goal[y][x] ? '+' : '.';
        point = {ny, nx};
    } else if (next == 'b' || next == 'B') {
        int nny = ny + dy[dir], nnx = nx + dx[dir];
        if (!valid(nny, nnx)) return;
        char next2 = board[nny][nnx];
        if (next2 == '#' || next2 == 'b' || next2 == 'B') return;

        board[nny][nnx] = goal[nny][nnx] ? 'B' : 'b';
        board[ny][nx] = goal[ny][nx] ? 'W' : 'w';
        board[y][x] = goal[y][x] ? '+' : '.';
        point = {ny, nx};
    }
}

void print_board(bool complete) {
    cout << "Game " << ++cnt << ": " << (complete ? "complete" : "incomplete") << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = board[i][j];
            cout<<c;
        }
        cout << "\n";
    }
}

void solve() {
    string cmd;
    cin >> cmd;

    if (isComplete()) {
        print_board(true);
        return;
    }

    for (char c : cmd) {
        if (c == 'U') move(0);
        else if (c == 'R') move(1);
        else if (c == 'D') move(2);
        else if (c == 'L') move(3);

        if (isComplete()) {
            print_board(true);
            return;
        }
    }

    print_board(false);
}

int main() {
    fastio();
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        init();
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m; j++) {
                board[i][j] = row[j];
                if (row[j] == 'W' || row[j] == 'w') point = {i, j};
                if (row[j] == '+' || row[j] == 'B' || row[j] == 'W') {
                    goal[i][j] = true;
                    answer++;
                }
            }
        }
        solve();
    }
    return 0;
}
