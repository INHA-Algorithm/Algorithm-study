#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N;
string arr[51];
int visit[51][51][4];
// 거울을 놓을수있는 형태는 2개 밖에 존재하지 않는다.
vector<pair<int, int>> v;


void input() {
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        arr[i] = s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '#')v.emplace_back(j, i);
        }
    }
}

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};
// / 경우 : 위->왼, 왼->위, 하->우, 우->하
// \ 경우 : 상->우, 우->상, 하->좌, 좌->하

// 아래랑 왼쪽이 깐부, 위랑 오른쪽이 깐부
int sol() {
    priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<> > q;
    for (int i = 0; i < 4; i++) {
        q.push({0, {i, {v[0].first, v[0].second}}});
    }
    while (!q.empty()) {
        int x = q.top().second.second.first;
        int y = q.top().second.second.second;
        int d = q.top().second.first;
        int mirror = q.top().first;
//        cout << "x : " << x << "/  y : " << y << "/  d : " << d << "/  mirror : " << mirror << '\n';
        if (x == v[1].first && y == v[1].second)return mirror;
        q.pop();
        // 상하좌우 순서로 dis배열이 정의 되어있다.
        int xx = x + xn[d];
        int yy = y + yn[d];
        if (yy < 0 || xx < 0 || yy >= N || xx >= N)continue;
        if (arr[yy][xx] == '*')continue;
        q.push({mirror, {d, {xx, yy}}});
        visit[yy][xx][d] = true;

        if (arr[yy][xx] == '!') { // 이경우에는 두가지의 방법이 가능함
            if (d == 0 || d == 1) {
                if (!visit[yy][xx][2]) {
                    q.push({mirror + 1, {2, {xx, yy}}});
                    visit[yy][xx][2] = true;
                }
                if (!visit[yy][xx][3]) {
                    q.push({mirror + 1, {3, {xx, yy}}});
                    visit[yy][xx][3] = true;
                }
            } else {
                if (!visit[yy][xx][0]) {
                    q.push({mirror + 1, {0, {xx, yy}}});
                    visit[yy][xx][0] = true;
                }
                if (!visit[yy][xx][1]) {
                    q.push({mirror + 1, {1, {xx, yy}}});
                    visit[yy][xx][1] = true;
                }
            }
        }

    }
}

int main() {
    input();
    cout << sol();
}
