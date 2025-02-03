//
// Created by 김석찬 on 2025/01/28.
//

#include<iostream>

#define MOD 9901

using namespace std;

int N;
int dp[100001][3]; // 1 : 왼쪽 , 2: 오른쪽


int main() {
    cin >> N;
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = (dp[i][0] + dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][2] + dp[i - 1][0]) % MOD;
        dp[i][2] = (dp[i][2] + dp[i - 1][1] + dp[i - 1][0]) % MOD;

    }
    cout << dp[N][0];

}
