//
// Created by 김석찬 on 2025/03/20.
//

#include<iostream>
#include <vector>
#include<queue>

using namespace std;

// 파이어볼 (y,x) 질량m, 방향 d, 질량 s
/*
같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
    파이어볼은 4개의 파이어볼로 나누어진다.
    나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
    질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
    속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
    합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
    질량이 0인 파이어볼은 소멸되어 없어진다.

 */

int N, M, K;

pair<pair<int, int>, pair<int, int>> arr[1005][54][54];
queue<pair<int, pair<int, int>>> v;
int xn[] = {0, 1, 1, 1, 0, -1, -1, -1};
int yn[] = {-1, -1, 0, 1, 1, 1, 0, -1};


void move(int x, int y, int s, int m, int flag, int cnt) {
    for (int j = flag; j < 8; j += 2) {
        int x_ = ((x + (xn[j]) * s) + (N*100000)) % N;
        int y_ = ((y + (yn[j]) * s )+ (N*100000)) % N;
        arr[cnt + 1][y_][x_].first.first++;
        arr[cnt + 1][y_][x_].first.second += m;
        arr[cnt + 1][y_][x_].second.first += s;
        if (arr[cnt + 1][y_][x_].first.first > 1) { // 1보다 크면 방향에 대해서 고민을 다같이 해봐야해요
            if (arr[cnt + 1][y_][x_].second.second != 10 && arr[cnt + 1][y_][x_].second.second % 2 != j % 2)
                arr[cnt + 1][y_][x_].second.second = 10;
            else if (arr[cnt + 1][y_][x_].second.second != 10 && arr[cnt + 1][y_][x_].second.second % 2 == j % 2) {
                if (j % 2 == 0)arr[cnt + 1][y_][x_].second.second = 8;
                else arr[cnt + 1][y_][x_].second.second = 9;
            }
        } else {
            arr[cnt + 1][y_][x_].second.second = j;
            v.push({cnt + 1, {x_, y_}});
        }
    }
}


void simul() {
    while (!v.empty()) {
        int x = v.front().second.first;
        int y = v.front().second.second;
        int cnt = v.front().first;

        if (cnt == K + 1)return;

        v.pop();



        int d = arr[cnt][y][x].second.second; // 방향
        int s = arr[cnt][y][x].second.first; // 속력
        int m = arr[cnt][y][x].first.second; // 질량
        int count = arr[cnt][y][x].first.first; // 깉은 칸에 있는 개수;
        if (count > 1) { // 나눠야함
            s = s / count;
            m = m / 5;
            if (m == 0)continue;
            if (d == 8 || d == 9) {
                move(x, y, s, m, 0, cnt);
            } else {
                move(x, y, s, m, 1, cnt);
            }
        } else {
            x = (x + (xn[d]) * s + (N*100000)) % N;
            y = (y + (yn[d]) * s + (N*100000)) % N;
            if (y < 0 || y >= N)y = y < 0 ? 0 : N - 1;
            arr[cnt + 1][y][x].first.first++;
            arr[cnt + 1][y][x].first.second += m;
            arr[cnt + 1][y][x].second.first += s;
            if (arr[cnt + 1][y][x].first.first > 1) { // 1보다 크면 방향에 대해서 고민을 다같이 해봐야해요
                if (arr[cnt + 1][y][x].second.second != 10 && arr[cnt + 1][y][x].second.second % 2 != d % 2)
                    arr[cnt + 1][y][x].second.second = 10;
                else if (arr[cnt + 1][y][x].second.second != 10 && arr[cnt + 1][y][x].second.second % 2 == d % 2) {
                    if (d % 2 == 0)arr[cnt + 1][y][x].second.second = 8;
                    else arr[cnt + 1][y][x].second.second = 9;
                }
            } else {
                arr[cnt + 1][y][x].second.second = d;
                v.push({cnt + 1, {x, y}});
            }

        }


    }
}


int main() {
    cin >> N >> M >> K;
    int x, y, m, s, d;
    for (int i = 0; i < M; i++) {
        cin >> y >> x >> m >> s >> d;
        arr[0][y - 1][x - 1] = {{1, m},
                                {s, d}};
        v.push({0, {x - 1, y - 1}});
    }
    simul();
    int ans=0;
    while(!v.empty()){
        ans+=arr[K+1][v.front().second.second][v.front().second.first].first.second;
        v.pop();
    }
    cout<<ans;



}