//
// Created by 김석찬 on 2025/02/10.
//

//
// Created by 김석찬 on 2022/10/26.
//

#include<iostream>

using namespace std;
pair<int, pair<int, int>> dp[41];
int T, N;

int fibo(int x) {

    if (dp[x].first)return dp[x].first;
    if (x == 0) {
        dp[x].second.first = 1;
        return 0;
    } else if (x == 1) {
        dp[x].second.second = 1;
        return 1;
    } else {
        dp[x].first = fibo(x - 1) + fibo(x - 2);
        dp[x].second.first = dp[x - 1].second.first + dp[x - 2].second.first;
        dp[x].second.second = dp[x - 1].second.second + dp[x - 2].second.second;
        return dp[x].first;
    }
}

int main() {
    cin >> T;
    fibo(40);
    while (T--) {
        cin >> N;
        cout << dp[N].second.first << " " << dp[N].second.second << '\n';
    }
}