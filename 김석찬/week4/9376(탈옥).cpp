//
// Created by 김석찬 on 2025/02/12.
//

#include<iostream>
#include<vector>
#include <queue>

#define INF 987654321
using namespace std;

/*
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.
첫째 줄에는 평면도의 높이 h와 너비 w가 주어진다. (2 ≤ h, w ≤ 100) 다음 h개 줄에는 감옥의 평면도 정보가 주어지며, 빈 공간은 '.', 지나갈 수 없는 벽은 '*', 문은 '#', 죄수의 위치는 '$'이다.
상근이는 감옥 밖을 자유롭게 이동할 수 있고, 평면도에 표시된 죄수의 수는 항상 두 명이다. 각 죄수와 감옥의 바깥을 연결하는 경로가 항상 존재하는 경우만 입력으로 주어진다.

 총 10000의 공간
 3980000개를 돌면서
 //
 */
int T;
int h, w;
int ans = INF;
char map[104][104];
int dist[104][104][3];
int visit[104][104][3];


vector<pair<int, int>> person;
vector<pair<int, int>> door;

int xn[] = {0, 0, -1, 1};
int yn[] = {1, -1, 0, 0};

void Init() {
    person.clear();
    door.clear();
}

void Input() {
    string s;
    for (int i = 1; i <= h; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            map[i][j + 1] = s[j];
            if (i == 1 || j == 0 || i == h || j == w - 1)
                if (s[j] == '#' || s[j] == '.') {
                    door.emplace_back(j + 1, i);
                }

            if (map[i][j + 1] == '$') { // 죄수의 위치
                person.emplace_back(j + 1, i);
                map[i][j + 1] = '.';
            }
        }
    }
}

void Sol(int a, int b, int cnt) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;
    Q.push({0, {a, b}});
    dist[b][a][cnt] = 0;


    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int d = Q.top().first;
        Q.pop();

        if (d > dist[y][x][cnt])continue;
        visit[y][x][cnt] = true;

        for (int i = 0; i < 4; i++) {
            int xx = x + xn[i];
            int yy = y + yn[i];
            if (xx < 0 || yy < 0 || xx > w + 1 || yy > h + 1)continue;
            if (visit[yy][xx][cnt])continue;
            if (map[yy][xx] == '*')continue;
            if (map[yy][xx] == '#') { // 문을 만나는 경우
                if (d + 1 < dist[yy][xx][cnt]) {
                    Q.push({d + 1, {xx, yy}});
                    dist[yy][xx][cnt] = d + 1;
                }
            } else {
                Q.push({d, {xx, yy}});
                dist[yy][xx][cnt] = d;
            }
        }
    }
}

int CalVal() {
    int result[104][104];
    int returnVal = INF;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= h + 1; j++) {
            for (int k = 0; k <= w + 1; k++) {
                if (map[j][k] == '*')continue;
                if(dist[j][k][i]==INF)continue;
                if (i == 0)result[j][k] = dist[j][k][0];
                else result[j][k] += dist[j][k][i];
                if (i == 2) {
                    if (result[j][k] == 0)return 0;
                    else {
                        if (map[j][k] == '#')result[j][k] -= 2;
                        returnVal = min(returnVal, result[j][k]);
                    }
                }
            }
        }
    }
    return returnVal;
}

void InitDist() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < h + 2; j++)
            for (int k = 0; k < w + 2; k++) {
                if(j==0 || k==0 || j==h+1 || k==w+1){
                    dist[j][k][i]=0;
                    map[j][k]='.';
                }else{dist[j][k][i] = INF;}
                visit[j][k][i] = false;
            }
}

int main() {
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> h >> w;
        Init();
        Input();
        InitDist();
        for (int j = 0; j < 3; j++) {
            int x, y;
            if (j == 2) {
                Sol(0, 0, j);
            } else {
                x = person[j].first;
                y = person[j].second;
                Sol(x, y, j);
            }
        }
        ans = min(ans, CalVal());

        cout << ans << '\n';


        ans = INF;
    }
}

