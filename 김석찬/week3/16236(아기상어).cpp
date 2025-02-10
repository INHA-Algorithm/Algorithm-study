#include<iostream>
#include<queue>

using namespace std;

pair<int, int> baby = {2, 0};
pair<int, int> start;
int n, total;
int arr[21][21];
int visit1[21][21];


int xn[] = {0, -1, 1, 0};
int yn[] = {-1, 0, 0, 1};

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                start = {i, j};
                arr[i][j] = 0;
            } else if (arr[i][j] > 0)total += 1;
        }
    }
}

int bfs(int count) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    visit1[start.first][start.second] = count;
    q.push({0, {start}});
    while (!q.empty()) {
        int x = q.top().second.second;
        int y = q.top().second.first;
        int cnt = q.top().first;
        if (baby.first > arr[y][x] && arr[y][x] != 0) { // 아기상어가 먹을수있음
            baby.second++;
            if (baby.second == baby.first) { // 아기상어 진화
                baby.first++;
                baby.second = 0;
            }
            arr[y][x] = 0;
            start = {y, x};
            return cnt;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + xn[i];
            int yy = y + yn[i];
            if (yy < 0 || xx < 0 || yy >= n || xx >= n)continue;
            if (visit1[yy][xx] == count)continue;
            if (baby.first < arr[yy][xx])continue;
            visit1[yy][xx] = count;
            q.push({cnt + 1, {yy, xx}});
        }
    }
    return 0;
}

int main() {
    int ans = 0;

    input();

    for (int i = 1; i <= total; i++) {
        int num = bfs(i);
        if (num)ans += num;
        else break;
    }
    cout << ans;
}