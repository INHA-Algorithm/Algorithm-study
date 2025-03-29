#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int ddx[4][10] = {{-2,-1,-1,-1,0,1,1,1,2,0}, {0,1,0,-1,2,1,0,-1,0,1}, {-2,-1,-1,-1,0,1,1,1,2,0}, {0,-1,0,1,-2,-1,0,1,0,-1}};

int ddy[4][10] = {{0,-1,0,1,-2,-1,0,1,0,-1}, {2,1,1,1,0,-1,-1,-1,-2,0}, {0,1,0,-1,2,1,0,-1,0,1}, {2,1,1,1,0,-1,-1,-1,-2,0}};
int rate[9] = {2, 10, 7, 1, 5, 10, 7, 1, 2};

int move_sands(int N, int tox, int toy, int dir, vector<vector<int> >& sand) { //움직이고 밖으로 나간 것들은 리턴
    int out = 0;
    int s = sand[tox][toy];
    int total = 0;
    for(int i=0; i<9; i++) {
        int nx = tox + ddx[dir][i]; int ny = toy + ddy[dir][i];
        if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1) out += (s*rate[i]*(0.01));
        else sand[nx][ny] += s*rate[i]*(0.01);
        total += s*rate[i]*(0.01);
    }
    int nx = tox + ddx[dir][9];
    int ny = toy + ddy[dir][9];
    if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1) out += (s-total);
    else sand[nx][ny] += (s-total);

    sand[tox][toy] = 0;

    return out;
}

int make_to(int N, vector<vector<int> >& sand) {
    int out = 0;
    int x = N/2; int y = N/2;
    for(int i=1; i<N; i += 2) {
        for(int j=i; j>0; j--) {
            x = x + dx[0]; y = y + dy[0];
            out += move_sands(N, x, y, 0, sand);
        }
        for(int j=i; j>0; j--) {
            x = x + dx[1]; y = y + dy[1];
            out += move_sands(N, x, y, 1, sand);
        }
        for(int j=i+1; j>0; j--) {
            x = x + dx[2]; y = y + dy[2];
            out += move_sands(N, x, y, 2, sand);
        }
        for(int j=i+1; j>0; j--) {
            x = x + dx[3]; y = y + dy[3];
            out += move_sands(N, x, y, 3, sand);
        }
    }
    for(int j=N-1; j>0; j--) {
        x = x + dx[0]; y = y + dy[0];
        out += move_sands(N, x, y, 0, sand);
    }
    return out;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int> > sand;
    sand.resize(N);
    for(int i=0; i<N; i++) {
        sand[i].resize(N);
        for(int j=0; j<N; j++) {
            cin >> sand[i][j];
        }
    }
    cout << make_to(N, sand) << endl;

    return 0;
}
