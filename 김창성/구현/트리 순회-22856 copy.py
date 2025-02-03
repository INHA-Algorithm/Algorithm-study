#제한
# 1초, 메모리 4096,000,000

#문제
# 유사 중위 순회를 하면서 이동한 총 횟수를 구해라
# 중위 탐색할때 탐색했던 곳도 다시 카운트

#입력
# 1 <= 노드개수 N <= 100,0000
# 1 <= a(부모),b(오른쪽 자식),c(왼쪽 자식) <= N
# -1 일때, 자식 없다는 것을 의미

#출력
# 이동한 총 횟수

import sys
sys.setrecursionlimit(10**6) # 파이썬 재귀깊이가 최대 1000이므로 늘려줘야함

n = int(input())
tree = [[] for _ in range(n+1)]

cnt = 0
ans = 0
visited = []

for i in range(n):
    root, left, right = list(map(int,input().split()))
    if left == -1: 
        left = 0
    if right == -1:
        right = 0
    tree[root].append(left)
    tree[root].append(right)


def inorder(t):
    global cnt, ans

    visited.append(t)

    if len(visited) == n:
        ans = cnt

    if tree[t][0]:
        cnt += 1 #자식으로 갈때
        inorder(tree[t][0])
        cnt += 1 #돌아 왔을때
        if len(visited) == n: #마지막 노드가 왼쪽 노드 일때
            ans = cnt
        
    if tree[t][1]:
        cnt += 1 #자식으로 갈때
        inorder(tree[t][1])
        cnt += 1  #돌아 왔을때

inorder(1)
print(ans)