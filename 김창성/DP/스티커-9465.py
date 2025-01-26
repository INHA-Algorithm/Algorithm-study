# 제한
# 1초, 메모리 1024,000,000

#문제
# 스티커를 뗄 때, 인접한 스티커는 찢어진다.
# 스티커에 부여된 점수가 최대가 되도록 스티커를 떼라

#입력
# 1 ≤ n (테스트케이스) ≤ 100,000
# 0 <= 점수 <= 100

#출력
# 스티커 점수 최댓값

#입력
# 1 ≤ N ≤ 100,000
# 0 ≤ 점수 score ≤ 100

#풀이
# 경우의 수 대각선 두번째 까지 고려 

def DP(N):
    dp = [[0]*(N+1) for _ in range(2)]
    array = []

    for _ in range(2):
        array.append([0]+list(map(int,input().split())))

    dp[0][1] = array[0][1]
    dp[1][1] = array[1][1]

    if N > 1:
        for i in range(2,N+1):
            top_value = dp[0][i-1] if dp[0][i-2] < dp[0][i-1] else dp[0][i-2]
            bottom_value = dp[1][i-1] if dp[1][i-2] < dp[1][i-1] else dp[1][i-2]
            
            dp[1][i] = top_value + array[1][i]
            dp[0][i] = bottom_value + array[0][i]
    
    return max(dp[0][N],dp[1][N])



if __name__ == "__main__":
    repeat = int(input())

    for _ in range(repeat):
        N = int(input())
        print(DP(N))

