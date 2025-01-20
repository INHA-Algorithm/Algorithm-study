/**
*
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	160496	52375	38319	31.050%
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

설명
 dp[i][j] => i 길이의 j로 끝나는 계단수의 개수
 dp[i][j]= dp[i-1][j+1]+d[i-1][j-1] 0과 9 제외
*/

#include <iostream>

#define ll long long
using namespace std;

const int MAX = 101;
const int DIVISOR = 1000000000;

ll dp[MAX][10];
int n;

void init() {
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
}

int main() {
    cin >> n;
    init();
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0 || j == 9) {
                //j가 0이면 1에서 오고 9면 8에서 옴.
                dp[i][j] = (j == 0) ? dp[i - 1][j + 1] : dp[i - 1][j - 1];
                dp[i][j] %= DIVISOR;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
                dp[i][j] %= DIVISOR;
            }
        }
    }
    ll ans = 0;
    for (auto i: dp[n])ans += i;
    cout << ans%DIVISOR;
}
