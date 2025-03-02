#제한
# 2초, 메모리 128,000,000

#문제
# 자연수 N을 자연수의 합으로 나타낼 때,
# 그 수의 분해 곱의 최댓값을 구해라

#입력
# 1 <= N <= 1,000,000

#출력
# 분해의 최댓값을 10,007로 나눈 나머지를 출력

#풀이
# 급수적으로 증가하는 e와 가까운 3의 곱으로 나타내야 함

def express_product(N):
    if N < 5 :
        return N

    num_3 = N // 3
    if N%3 == 1:
        return pow(3,num_3-1)*2*2
    elif N%3 == 2:
        return pow(3,num_3)*2
    return pow(3,num_3)

if __name__ == "__main__":
    N = int(input())
    print(express_product(N)%10007)

