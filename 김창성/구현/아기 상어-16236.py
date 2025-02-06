#제한
# 2초, 메모리 2048,000,000

#문제
# 아기 상어가 물고기를 잡아먹을 때 걸리는 시간(초)를 구해라
# 상어는 초기 크기는 2, 크기만큼의 물고기를 잡아먹으면 +1
# 크기보다 작은 물고기 먹기O, 같은 크기는 지나갈 수 있음.
# 가까운 물고기가 많으면 가장 위, 가장 왼쪽 순으로 먹는다.
# 더 이상 먹을 수 있는 물고기가 없으면 stop

#입력
# 2 ≤ 공간 크기 N ≤ 20
# 0: 빈 칸
# 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
# 9: 아기 상어의 위치

#출력
# 물고기를 잡아먹을 수 있는 시간을 출력

#풀이
# 1.먹을 수 있는 물고기 위치 찾기
# 2.이동, 크기가 큰 물고기 고려해서
# 3.상어 크기 count

from collections import deque

def calculateDistance(array,N, start, goal, sharkScale):
    visited = [[False]*N for _ in range(N)]
    que = deque([(0,start[0],start[1])])
    visited[start[0]][start[1]] = True

    while que:
        distance, x, y = que.popleft()

        if goal == (x,y):
            return distance

        for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
            nx, ny = dx+x, dy+y

            if N > nx >= 0 and N > ny >= 0 and array[nx][ny] <= sharkScale and visited[nx][ny]==False:
                visited[nx][ny] = True
                que.append((distance+1, nx, ny))

    return -1

def findFishLocation(array, N, sharkScale, sharkLocation):
    fishLocations = []

    for i in range(N):
        for j in range(N):
            if  0 < array[i][j] < sharkScale:
                gap = calculateDistance(array, N, sharkLocation, (i,j), sharkScale)
                
                if gap > 0:
                    fishLocations.append((gap,i,j))

    fishLocations.sort(key = lambda x:(x[0],x[1],x[2]))
    return fishLocations

def countTime(array, N):
    sharkLocation = (-1,-1)
    sharkScale = 2
    moveCount = 0
    scaleCount = 0

    for i in range(N):
        for j in range(N):
            if array[i][j] == 9:
                sharkLocation = (i,j)
                array[i][j]=0

    while(True):
        fishLocation = findFishLocation(array, N, sharkScale, sharkLocation)
        
        if len(fishLocation) == 0:
            break
       
        gab, x, y = fishLocation[0]
        moveCount += gab
        sharkLocation = (x,y)

        array[x][y] = 0
        scaleCount += 1

        if scaleCount == sharkScale:
            sharkScale += 1
            scaleCount = 0

    return moveCount

if __name__ == "__main__":
    N = int(input())
    array = []

    for _ in range(N):
        array.append(list(map(int,input().split())))

    print(countTime(array, N))