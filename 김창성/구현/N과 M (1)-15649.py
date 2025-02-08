#제한
# 1초, 2048,000,000

#문제
# N과 M이 주어졌을 때, 
# 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 출력

#입력
# 1 ≤ M ≤ N ≤ 8

#출력
# 각 수열은 공백으로 구분해서 출력해야 한다.
# 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

#풀이
# 백트래킹 사용
# https://veggie-garden.tistory.com/24

def backTracking(array,N,M):
    if len(array) == M:
        print(" ".join(map(str,array)))
        return

    for i in range(1,N+1):
        if i not in array:
            array.append(i)
            backTracking(array,N,M)
            array.pop()


if __name__ == "__main__":
    N, M = map(int,input().split())
    array = []

    backTracking(array,N,M)
