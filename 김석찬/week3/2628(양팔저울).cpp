//
// Created by 김석찬 on 2025/02/09.
//

#include<iostream>

using namespace std;

int N, qNum;
int v[31];
int dp[31][40001];

int main() {
    cin >> N;
    int a;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        v[i]=a;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 40001; j++) {
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (v[i] == j){
                dp[i][j] = j;
            }
            else if (v[i] < j) { // 현재 보고있는 추의 무게가 더 클때
                dp[i][j] = (dp[i - 1][j - v[i]] + v[i] == j) || (dp[i - 1][j + v[i]] - v[i] == j) ? j : dp[i - 1][j];
            } else if (v[i] > j) { // 현재 보고있는 추의 무게가 더 작을때
                dp[i][j] = (v[i] - dp[i - 1][v[i] - j] == j) || (dp[i - 1][j + v[i]] - v[i] == j) ? j : dp[i - 1][j];
            }
        }
    }


    cin >> qNum;
    // 확인할 구슬의 개수는 7이하이다.
    for (int i = 0; i < qNum; i++) {
        cin >> a;
        if (dp[N][a] == a) {
            cout << "Y" << ' ';
        } else {
            cout << "N" << ' ';
        }
    }
}

