#제한
# 1초, 1024,000,000

#문제
# 계단 수가 총 몇 개 있는지 구해라
# 계단 수란: 인접한 수의 차이가 1인 연속된 수, 0으로 시작하는 것은 계단 수가 아님

#입력
# 1<= N <= 100

#출력
# 정답을 1,000,000,000으로 나눈 나머지

#풀이
# 배열 [자리수+1][10]
# 0이 첫번째로 올 수 없으니까 0배열을 결과값에 더하지 않음, 값을 구하는 용도로만
# 9는 뒤에 8밖에 못옴

def DP(array,N):
    
    if N > 1:
        for j in range(2,N+1):
            for i in range(10):
                if i == 0:
                    array[j][i] = array[j-1][i+1]
                elif i == 9:
                    array[j][i] = array[j-1][i-1]
                else:
                    array[j][i] = array[j-1][i-1] + array[j-1][i+1]

    print(sum(array[N][1:10])%1000000000)


if __name__ == "__main__":
    N = int(input())
    array = [[0]*10 for _ in range(N+1)] 
    

    for i in range(10):
        array[1][i] = 1

    DP(array,N)