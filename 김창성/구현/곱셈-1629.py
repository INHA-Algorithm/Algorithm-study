#제한
# 0.5초, 메모리 512,000,000

#문제
# 자연수 A를 B번 곱한 수를 C로 나눈 나머지를 구해라

#입력
# A, B, C는 모두 2,147,483,647 이하의 자연수

#출력
# A를 B번 곱한 수를 C로 나눈 나머지를 출력

#풀이
# A**B == A**(B/2)*A**(B/2)


def square(A,B,C):
    if B == 1:
        return A%C
    elif B%2 == 0:
        return (square(A, B//2,C)**2)%C
    else:
        return (square(A, B//2,C)**2*A)%C

if __name__ == "__main__":
    A, B, C = list(map(int,input().split()))

    print(square(A,B,C))