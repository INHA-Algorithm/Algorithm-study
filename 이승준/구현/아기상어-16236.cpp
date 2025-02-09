#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 21

struct Cell {
    int x;
    int y;
    int dist;

    Cell(int x, int y, int dist) : x(x), y(y), dist(dist) {};
};

void input();

void solve();

void bfs();

void init();

int n, eatTime;

vector<vector<int>> map(MAX, vector<int>(MAX));
bool visited[MAX][MAX];
pair<int, int> sharkPos;
pair<int, int> shark = {2, 0};

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int main() {
    input();
    solve();
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sharkPos = {i, j};
            }
            //상어의 위치
        }
    }
}

bool check(int ny, int nx) {
    if (ny < 1 || ny > n || nx < 1 || nx > n)return false;
    if (visited[ny][nx])return false;
    if (shark.first < map[ny][nx])return false;
    return true;
}

void bfs() {
    queue<Cell> q;
    q.emplace(sharkPos.second, sharkPos.first, 0);
    vector<pair<int, pair<int, int>>> fishes;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            //인접한 칸 이동
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int ndist = cur.dist + 1;

            //불가능한 칸 안감.
            if (!check(ny, nx))continue;
            visited[ny][nx] = true;
            q.emplace(nx, ny, ndist);

            //먹을 수 있는 생선이면 배열에 추가.
            if (map[ny][nx] < shark.first && map[ny][nx] != 0) {
                fishes.push_back({ndist, {ny, nx}});
            }
        }
    }

    if (!fishes.empty()) {
        // 가까운순, 윗열, 왼쪽순으로 정렬.
        sort(fishes.begin(), fishes.end());

        int ny = fishes[0].second.first;
        int nx = fishes[0].second.second;
        int ndist = fishes[0].first;

        //상어 위치 이동.
        map[sharkPos.first][sharkPos.second] = 0;
        map[ny][nx] = 9;
        sharkPos = {ny, nx};

        // 사이즈 업
        shark.second++;
        if (shark.second == shark.first) {
            shark.first++;
            shark.second = 0;
        }
        // 먹이를 먹을 수 있는 시간
        eatTime += ndist;
    }

}

void solve() {
    while (true) {
        //before
        int old = eatTime;

        visited[sharkPos.first][sharkPos.second] = true;

        bfs();

        //after
        if (eatTime == old) break;
        init();
    }
    cout << eatTime;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}
