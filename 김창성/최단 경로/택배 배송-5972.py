#제한
# 1초, 메모리 512,000,000

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
# 플로이드 워셜 알고리즘 - 거쳐가는 경로 중 최단 경로로 업데이트

def findmin(N, array):

    for k in range (1,N+1): #거쳐가는 노드
        for i in range (1,N+1): #시작 노드
            for j in range (1,N+1): #도착 노드
                if(array[i][k] != 10001 and array[k][j] != 10001):
                    array[i][j] = min(array[i][j], array[i][k] + array[k][j]) 

    return array[1][N]

if __name__ == "__main__":
    N, M = map(int,input().split())
    array = [[10001]*(N+1) for _ in range(N+1)]

    for _ in range(M):
        i, j, c = map(int,input().split())
        array[i][j] = c
        array[j][i] = c
    
    print(findmin(N, array))
