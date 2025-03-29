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
#define MAX 1025

int n, m, X1, X2, Y1, Y2, k;

int board[MAX][MAX];
int dp[MAX][MAX];

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
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            dp[i][j] = board[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
}

void solve() {
    cin >> k;

    while (k--) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << dp[X2][Y2] - dp[X1 - 1][Y2] - dp[X2][Y1 - 1] + dp[X1 - 1][Y1 - 1] << "\n";
    }

}