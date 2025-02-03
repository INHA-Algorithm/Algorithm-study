
/**
 * 우선 dp[i][j]는 i열 j행 까지의 최대값.
 * dp[0][j]= value[0][j]+max(dp[1][j-2],dp[1][j-1]);
 * dp[1][j] = value[1][j]+ max(dp[0][j-2],dp[0][j-1]);
 *
 * */

#include<iostream>
#include <vector>
#include<cmath>

using namespace std;

const int MAX = 100001;
int n;
int dp[2][MAX];
int buf[2][MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a, b;
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> buf[j][i];
            }
        }
        dp[0][1] = buf[0][1];
        dp[1][1] = buf[1][1];
        dp[0][2] = dp[1][1] + buf[0][2];
        dp[1][2] = dp[0][1] + buf[1][2];
        for (int j = 3; j <= n; j++) {
            dp[0][j] = buf[0][j] + max(dp[1][j - 2], dp[1][j - 1]);
            dp[1][j] = buf[1][j] + max(dp[0][j - 2], dp[0][j - 1]);
        }
        cout << max(dp[0][n], dp[1][n])<<"\n";
    }
}

