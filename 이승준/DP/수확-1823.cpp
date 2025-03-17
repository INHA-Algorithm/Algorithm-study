#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[2001];
int dp[2001][2001];

int solve(int left, int right, int count){
    if(left > right) return 0; // 왼쪽 값이 오른쪽보다 큰건 존재안함
    if(dp[left][right]) return dp[left][right]; // 이미 계산된 거면 그 값 반환

    // 점화식
    int val = max(solve(left+1,right,count+1)+ map[left]*count,
                  solve(left,right-1,count+1)+ map[right]*count);

    return dp[left][right] = val;
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> map[i];

    cout << solve(1,N,1);
}