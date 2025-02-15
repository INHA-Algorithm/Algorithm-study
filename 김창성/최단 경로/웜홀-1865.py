#제한
# 2초, 128,000,000

#문제
# N개의 지점, M개의 도로 와 W개의 웜홀이 있다 (도로는 방향x, 웜홀 방향o)
# 웜홀을 만나면 시간이 뒤로 간다.
# 출발해서 다시 되돌아 왔을때, 시간이 되돌아가 있는 경우가 있는지 확인해라

#입력
# 1 ≤ 테스트게이스 TC ≤ 5
# 1 ≤ 지점의 수 N ≤ 500
# 1 ≤ 도로의 개수 M ≤ 2500 
# 1 ≤ 웜홀의 개수 W ≤ 200
# 시작지점 S, 도착지점 E
# 0 < 이동시간 T <= 10,000

#출력
# 시간이 줄어들면서 출발 위치로 돌아오는 것이 가능하면 YES, 아니면 NO 출력

#풀이
# 플로이드 워셜 알고리즘 - 거쳐가는 경로 중 최단 경로로 업데이트 -> 시간 초과 n^3 -> X
# 벨만 포드 알고리즘 ->


def checkTime(N, road):
    dis = [10001]*(N+1)
    #dis[1] = 0  #음의 사이클을 구하는 문제임으로 필요없음 

    for i in range (N): #각 노드 간 최단거리 구하기
        for s, e, t in road:
            if dis[e] > dis[s] + t:
                dis[e] = dis[s] + t
                
    for s, e, t in road: #N번 반복 후에도 업데이트가 이루어진다면 음수가 존재
        if dis[e] > dis[s] + t:
            return True
    return False

if __name__ == "__main__":
    TC = int(input())
    
    for _ in range(TC):
        N, M, W = map(int,input().split()) # 3 3 1
        road = []

        for _ in range(M):
            s, e, t = map(int,input().split()) #도로 추가 방향 없음
            road.append((s,e,t))
            road.append((e,s,t))
        
        for _ in range(W):
            s, e, t = map(int,input().split()) # 웜홀 추가 방향 있음
            road.append((s,e,-t))


        if checkTime(N, road):
            print("YES")
        else:
            print("NO")

        
    


