#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int T;
int dp[2][100001]; // 뜯거나 말거나
int map[2][100001];

int main() {
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int num;
        cin >> num;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= num; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = map[i][1];
            }
        }
        for (int i = 2; i <= num; i++) {
            dp[0][i] = map[0][i] + max(dp[1][i-1],dp[1][i-2]);
            dp[1][i] = map[1][i] + max(dp[0][i-1],dp[0][i-2]);
        }
        cout<<max(dp[0][num],dp[1][num])<<'\n';

    }
}

/*
50 10 100 20 40
30 50 70 10 60

50 50 40 200 140 250
30 30 100 120 210 260

10 30 10 50 100 20 40
20 40 30 50 60 20 80
 */