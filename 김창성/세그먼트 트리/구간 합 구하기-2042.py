#제한
# 2초, 256,000,000

#문제
# 중간에 수를 바꾸었을때, 구간의 합을 구해라
# 1: 숫자 변경, 2: 출력

#입력
#  1 ≤ 수의 개수 N ≤ 1,000,000 
# 1 ≤ 출력 횟수 K, 변경 횟수 M ≤ 10,000
# -2^63 <= number <= 263-1

#출력
# 구간 합 출력

N, K, M = map(int,input().split())
num = [int(input()) for _ in range(N)]

tree = [0]*(N*4)

def build_tree(current, start, end):
    if start == end:
        tree[current] = num[start]
        return num[start]

    mid = (start+end)//2
    left_sum = build_tree(current*2,start,mid)
    right_sum = build_tree(current*2+1,mid+1,end)

    tree[current] = left_sum + right_sum
    return tree[current]

def update_tree(current, start, end, index, value):
    if start == end:
        if start == index:
            tree[current] = value
        return

    mid = (start+end)//2
    if index > mid:
        update_tree(current*2+1,mid+1,end, index, value)
    else:
        update_tree(current*2,start,mid, index, value)

    tree[current] = tree[current*2] + tree[current*2+1]


def range_total(current, start, end, b, c):
    if b <= start and end <= c:
        return tree[current]
    if b > end or start > c:
        return 0

    mid = (start+end)//2
    total = range_total(current*2+1,mid+1,end, b, c)
    total += range_total(current*2,start,mid, b, c)

    return total


build_tree(1,0,N-1)

for i in range(K+M):
    type, b, c = map(int,input().split())

    if type == 1:
        update_tree(1,0,N-1,b-1,c)
    else:
        print(range_total(1, 0, N-1, b-1, c-1))
    