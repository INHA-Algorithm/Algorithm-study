#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

int n;
bool map[101][101];

void solve();

void input();

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};


int main() {
    fastio();
    input();
    solve();
}

//0단계는 스킾.
void dragonCurve(vector<int> dirs, int y, int x, int gen, int curGen) {
    if (curGen == gen) {
        map[y][x] = true;
        for (auto a: dirs) {
            y += dy[a];
            x += dx[a];
            map[y][x] = true;
        }
        return;
    }
    vector<int> prev = dirs;
    reverse(prev.begin(), prev.end());
    for (int dir: prev) {
        dirs.push_back((dir + 1) % 4);
    }
    dragonCurve(dirs, y, x, gen, curGen + 1);
}

void input() {
    cin >> n;
}

void solve() {
    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> temp = {d};
        dragonCurve(temp, y, x, g, 0);
    }
    // 네모인지 체크.
    int ans = 0;
    for (int i = 100; i > 0; i--) {
        for (int j = 0; j < 100; j++) {
            bool isTrue = true;
            int ny = i;
            int nx = j;
            for (int dir = 0; dir < 4; dir++) {
                ny += dy[dir];
                nx += dx[dir];
                if (!map[ny][nx])isTrue = false;
            }
            if (isTrue) {
                ans++;
            }
        }
    }
    cout << ans;
}
