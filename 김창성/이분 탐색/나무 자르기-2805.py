#제한
# 1초, 256,000,000

#문제
# N개의 나무를 잘라 같은 높이로 잘라,
# 원하는 길이만 가져가기 위한 최대 높이를 구해라

#입력
# 1 ≤ 나무의 수 N ≤ 1,000,000
# 1 ≤ 나무의 길이 M ≤ 2,000,000,000
# 1 ≤ 나무의 높이 L ≤ 1,000,000,000

#출력
# 절단할 수 있는 최대 나무 높이

#풀이
# 이분 탐색


def search(trees,M):
    start, end = 1, sum(trees)

    while start <= end:
        total = 0
        mid = (start + end)//2

        for tree in trees:
            if tree > mid:
                total += tree - mid

        if total >= M:
            start = mid + 1
        else:
            end = mid -1 
    
    return end


if __name__ == "__main__":
    N, M = map(int,input().split())
    trees = list(map(int, input().split()))

    print(search(trees,M))

