#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 51
int n, m, ans;
int matrixA[MAX][MAX];
int matrixB[MAX][MAX];

void input();

void solve();


int main() {
    fastio();
    input();
    solve();
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string cmd;
        cin >> cmd;
        int j = 1;
        for (auto ele: cmd) {
            matrixA[i][j++] = (ele == '1') ? 1 : 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        string cmd;
        cin >> cmd;
        int j = 1;
        for (auto ele: cmd) {
            matrixB[i][j++] = (ele == '1') ? 1 : 0;
        }
    }
}

void turn(int y, int x) {
    ans++;
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            matrixA[i][j] = (matrixA[i][j] == 1) ? 0 : 1;
        }
    }
}

void solve() {
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j <= m - 2; j++) {
            if (matrixA[i][j] != matrixB[i][j]) {
                turn(i, j);
            }
//            printf("y: %d , x: %d\n",i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrixA[i][j] != matrixB[i][j]) {
                cout << -1;
                return;
            }
        }
    }
    cout << ans;
}