//
// Created by 김석찬 on 2025/03/20.
//

#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];
int N;

int sol(int left, int right, int count) {
    if (left > right)return 0;
    if (dp[left][right] != 0)return dp[left][right];
    return dp[left][right] = max((sol(left + 1, right, count + 1) +arr[left] * count),
                                 (sol(left, right - 1, count + 1) +arr[right] * count));
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cout<<sol(1,N,1);
}