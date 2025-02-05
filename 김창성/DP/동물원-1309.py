#제한
# 2초, 메모리 512,000,000

#문제
# 가로 2칸 세로 N칸의 우리에서 동물이 가로 세로로
# 만나지 못하게 가두는 경우의 수 구해라

#입력
# (1 ≤ 우리의 크기 N ≤ 100,000)

#출력
# 9901로 나눈 나머지

#풀이
# 점화식 dp[i] = 2*dp[i-1] + dp[i-2]

def DP(N):
    dp = [1]*(N+1)

    dp[1] = 3

    for i in range(2,N+1):
        dp[i] = 2*dp[i-1] + dp[i-2]

    return dp[N]

if __name__ == "__main__":
    N = int(input())

    print(DP(N))