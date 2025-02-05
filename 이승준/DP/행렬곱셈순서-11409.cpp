#include<iostream>

using namespace std;
int INF=987654321;
int MAX = 505;
int dp[505][505];
int p[505];
int n;

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    int r, c;
    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        p[i] = r;
        p[i + 1] = c;
        dp[i][i] = 0;
    }

    dp[n][n] = 0;
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                int val = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
//                cout << i << j << k << " " << val << endl;
                dp[i][j] = min(dp[i][j], val);
            }
        }
    }
    cout << dp[1][n];
}