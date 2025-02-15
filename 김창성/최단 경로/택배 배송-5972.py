#제한
# 1초, 메모리 128,000,000

#문제
# 1에서 N헛간을 갈 때, 필요한 최소 여물을 구해라

#입력
# 1 <= 헛간 N <= 50,000
# 1 <= 소들의 길 M <= 50,000
# 0 <= 소의 수 C_i <= 1,000
# 헛간 번호 A_i, B_i

#출력
# 최소 여물을 출력

#풀이
# 다익스트라 알고리즘
# 1. 출발점에서 근접 노드 비용 업데이트
# 2. 방문하지 않은 노드 중 인접한 노드중 비용이 작은 거리부터 계산 업데이트

import heapq

def findmin(N, graph, start):
    dis = [1001*N]*(N+1) #모든 노드를 거쳐가는 비용을 합쳤으니까 1001으로 초기화하면 안됨
    dis[start] = 0

    que = []
    heapq.heappush(que,(0,start)) #비용을 먼저 넣어야 최소비용부터 pop

    while que:
        current_cost,  current = heapq.heappop(que)

        if current_cost > dis[current]: #힙에서 최소비용이 아닌거 꺼내면 패스
            continue 

        for next, next_cost in graph[current]:
            new_cost = next_cost + current_cost #주의
            if dis[next] > new_cost:
                dis[next] = new_cost
                heapq.heappush(que,(new_cost,next))
    
    return dis[N]

if __name__ == "__main__":
    N, M = map(int,input().split())
    graph = [[] for _ in range(N+1)]

    for _ in range(M):
        i, j, c = map(int,input().split())
        graph[i].append((j,c))
        graph[j].append((i,c))

    print(findmin(N, graph, 1))
