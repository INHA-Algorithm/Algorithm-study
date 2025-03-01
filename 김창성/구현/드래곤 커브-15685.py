#제한
# 1초, 512,000,000

#문제
# K세대 드래곤 커브는 K-1세대 드래곤 커브를 
# 90도 시계 방향 회전 후, 끝 점에 붙인 것이다.
# 100 x 100 격자 위에 드래곤 커브 N개가 있을 때,
# 드래곤 커브로 이루어진 정사각형 개수를 구해라

#입력
# 1 ≤ 드래곤 커브 개수 N ≤ 20
# 0 ≤ 좌표 x, y ≤ 100
# d = 0 (-> x좌표 +1), 1 (^ y좌표 -1), 2 (<- x좌표 -1), 3 (v y좌표 +1)
# 0 ≤ 세대 g ≤ 10

#출력
# 1 x 1 정사각형의 네 꼭짓점 드래곤 커브의 일부인 것의 개수

if __name__ == "__main__":
    N = int(input())
    array = [[0]*101 for _ in range(101)]
    # d=0 (x+1), d=1 (y-1), d=2 (x-1), d=3 (y+1)
    dy = [0,-1,0,1] 
    dx = [1,0,-1,0] 

    for _ in range(N):
        x, y, d, g = map(int, input().split())
        array[y][x] = 1 #시작
        curve = [d]

        for _ in range(g): #이동방향 추가
            for i in range(len(curve)-1,-1,-1):
                curve.append((curve[i]+1)%4)
        
        for i in curve:
            x, y = x + dx[i], y + dy[i]
            array[y][x] = 1

    result = 0
    for i in range(100):
        for j in range(100):
            if array[i][j] and array[i+1][j] and array[i][j+1] and array[i+1][j+1]:
                result += 1
    print(result)
            
