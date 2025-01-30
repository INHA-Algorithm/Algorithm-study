#제한
# 1초, 메모리 1024,000,000

#문제
# 행렬을 곱할 때 곱셉 연산 횟수의 최솟값을 구해라
# 단, 입력으로 주어진 행렬의 순서를 바꾸면 안됨

#입력
# 1 ≤ 행렬의 개수 N ≤ 500
# 1 ≤ 행렬의 크기 r, c ≤ 500

#출력
# 곱셈 연산의 최솟값 (연산 횟수가 2^31-1보다 작거나 같다.)

#풀이
# https://one-way-people.tistory.com/38
# https://ddiyeon.tistory.com/72

if __name__ == "__main__":
    n = int(input())
    mat = [tuple(map(int, input().split())) for i in range(n)]

    dp = [[0]*n for i in range(n)]
    for cnt in range(n-1):
        for i in range(n-1-cnt):
            j = i+cnt+1
            dp[i][j] = 2**31
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + mat[i][0]*mat[k][1]*mat[j][1])
    print(dp[0][-1])
