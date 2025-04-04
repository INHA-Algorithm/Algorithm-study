#include <bits/stdc++.h>

#define MAX 16
using namespace std;


// U,D,L,R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char graph[MAX][MAX];
/**
 * # : 벽
 * . : 공간
 * + : 목표
 * b,B : 박스
 * w,W : 주인공
 */
int R, C;
struct ptr {
    int r;
    int c;
};
ptr man;
string input;
int rnd;

vector<int> cmd;


void init() {
    cin >> R >> C;
    if (!R || !C) { exit(0); }
    for (int r = 0; r < R; r++) {
        cin >> input;
        for (int c = 0; c < C; c++) {
            graph[r][c] = input[c];
            if (graph[r][c] == 'w' || graph[r][c] == 'W') {
                man = {r, c};
            }
        }
    }

    cmd.clear();
    cin >> input;
    for (char c: input) {
        if (c == 'U') {
            cmd.push_back(0);
        } else if (c == 'D') {
            cmd.push_back(1);
        } else if (c == 'L') {
            cmd.push_back(2);
        } else {
            cmd.push_back(3);
        }
    }
}

void mv_box(int r, int c, int d) {
    int nr = r + dr[d];
    int nc = c + dc[d];

    if (graph[nr][nc] == '.') {
        graph[nr][nc] = 'b';
        graph[r][c] = graph[r][c] == 'b' ? '.' : '+';
    } else if (graph[nr][nc] == '+') {
        graph[nr][nc] = 'B';
        graph[r][c] = graph[r][c] == 'b' ? '.' : '+';
    }
}
bool isRemain(){
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (graph[r][c] == '+' || graph[r][c] == 'W') {
                return true;
            }
        }
    }
    return false;
}

void print(bool flag) {
    cout << "Game " << ++rnd << ": ";
    if (flag) cout << "in";
    cout << "complete\n";
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << graph[r][c];
        }
        cout << '\n';
    }
}

void play() {
    for (int dir: cmd) {
        int nr = man.r + dr[dir];
        int nc = man.c + dc[dir];
        if (graph[nr][nc] == 'B' || graph[nr][nc] == 'b') {
            mv_box(nr, nc, dir);
        }
        if (graph[nr][nc] == '.') {
            graph[nr][nc] = 'w';
            graph[man.r][man.c] = graph[man.r][man.c] == 'w' ? '.' : '+';
            man = {nr, nc};
        } else if (graph[nr][nc] == '+') {
            graph[nr][nc] = 'W';
            graph[man.r][man.c] = graph[man.r][man.c] == 'w' ? '.' : '+';
            man = {nr, nc};
        }
        bool flag = isRemain();
        if(flag)continue;
        print(flag);
        return;
    }
    print(isRemain());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        init();
        play();
    }

}
