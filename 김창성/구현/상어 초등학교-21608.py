#제한
# 1초, 메모리 4096,000,000

#문제
# N*N의 교실에서 아래 3가지 규칙으로 자리를 정하고 만족도 합을을 구해라
# 1. 비어있는 칸 중에서 좋아하는 학생이 많이 인접한 칸
# 2. 1을 만족하는 칸이 여러 개면, 비어있는 칸이 많이 인접한 칸
# 3. 2를 만족하는 칸이 여러 개면, 행, 열의 번호가 가장 작은 칸

#입력
# 3 ≤ N ≤ 20
# 1 ≤ 좋아하는 학생 번호 liked_student_num ≤ N^2

#출력
# 학생 만족도의 총 합
# 학생 만족도: 인접한 칸에 앉은 좋아하는 학생의 수
#             - 1이면 1, 2이면 10, 3이면 100, 4이면 1000

#풀이
# 빈칸 탐색
# 1. 주변 좋아하는 학생 수 세기 -> 자리 배열 반환
# 2. 주변 빈칸 세기
# 3. 행, 열 번호 작은 칸 

def countLikedStudent(N, classSeat, key, likedStudentArray):
    maxCount = 0
    maxCountSeat = []

    for i in range(N):
        for j in range(N):
            likedStudentNum = 0

            if classSeat[i][j] == 0:
                for dx, dy in [(0,-1),(-1,0),(0,1),(1,0)]:
                    nx, ny = i+dx, j+dy
                    
                    if N > nx >= 0 and N > ny >= 0:
                        if classSeat[nx][ny] in likedStudentArray[key]:
                            likedStudentNum += 1
                
                if likedStudentNum > maxCount:
                    maxCount = likedStudentNum
                    maxCountSeat = []
                    maxCountSeat.append((i,j))
                elif likedStudentNum == maxCount:
                    maxCountSeat.append((i,j))
    
    return maxCountSeat


def countEmptySeat(N, classSeat, BestSeat):
    maxCount = 0
    maxCountSeat = []

    for i, j in BestSeat:
        EmptySeatNum = 0

        for dx, dy in [(0,-1),(-1,0),(0,1),(1,0)]:
            nx, ny = i+dx, j+dy
            
            if N > nx >= 0 and N > ny >= 0 and classSeat[nx][ny] == 0:
                EmptySeatNum += 1
        
        if EmptySeatNum > maxCount:
            maxCount = EmptySeatNum
            maxCountSeat = []
            maxCountSeat.append((i,j))
        elif EmptySeatNum == maxCount:
            maxCountSeat.append((i,j))
    
    return maxCountSeat


def calculateSatisfaction(classSeat, N, likedStudentArray):
    totalSatisfaction = 0

    for i in range(N):
        for j in range(N):
            currentSeat = classSeat[i][j]
            likedStudentNum = 0

            for dx, dy in [(0,-1),(-1,0),(0,1),(1,0)]:
                nx, ny = i+dx, j+dy
                
                if N > nx >= 0 and N > ny >= 0:
                    if classSeat[nx][ny] in likedStudentArray[currentSeat]:
                        likedStudentNum += 1
            
            if likedStudentNum > 0:
                totalSatisfaction += 10**(likedStudentNum-1)

    return totalSatisfaction


def ChooseSeat(N,likedStudentArray):
    classSeat = [[0]*N for _ in range(N)]

    for key in likedStudentArray:
        #print("현재 키",key)

        BestSeat = countLikedStudent(N, classSeat, key, likedStudentArray)
        #print("좋아하는 학생",BestSeat)

        if len(BestSeat) == 1:
            i, j = BestSeat[0]
            classSeat[i][j] = key
            continue
        
        BestSeat = countEmptySeat(N, classSeat, BestSeat)
        #print("빈자리",BestSeat)

        #빈 배열이 적은 배열로 초기화 한 뒤 자리 배정
        #열, 행 순으로 추가하기 때문에 정렬 X
        i, j = BestSeat[0]
        classSeat[i][j] = key

    return calculateSatisfaction(classSeat, N, likedStudentArray)
    

if __name__ == "__main__":
    N = int(input())
    likedStudentArray = dict()

    for _ in range(N**2):
        tempArray = list(map(int,input().split()))
        likedStudentArray[tempArray[0]] = tempArray[1:]

    print(ChooseSeat(N,likedStudentArray))