#include<iostream>
#include<vector>
using namespace std;

int N, M, K;

int arr[1025][1025];
int dp[1025][1025];

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j] + arr[i][j] + arr[i][j - 1];
            arr[i][j] = arr[i][j] + arr[i][j - 1];
        }
    }
}

int sol(int x1, int y1, int x2, int y2) {
    return dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    init();
    cin >> K;
    int x1, y1, x2, y2;
    for (int i = 0; i < K; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << sol(x1, y1, x2, y2) << '\n';
    }


}