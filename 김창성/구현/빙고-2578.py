#제한 
# 1초, 메모리 512,000,000

#문제
# 3번째 빙고를 외치게 되는 최소 수를 찾아라

#입력
# 1~25

#출력
# 3번째 빙고를 외치게 되는 최소 수

#풀이
# 13번째 수부터 가로 세로 줄, 대각선 점검

N = 5

def findNum(bingoBoard, currentNum): #숫자 지우기
    for i in range(N):
        for j in range(N):
            if bingoBoard[i][j] == currentNum:
                bingoBoard[i][j] = 0
                return bingoBoard


def checkRow(i):
    for j in range(N): 
        if bingoBoard[i][j] != 0:
            return False
    return True


def checkCol(i):
    for j in range(N): 
        if bingoBoard[j][i] != 0:
            return False
    return True


def checkCross1():
    for i in range(N):
        if bingoBoard[i][i] != 0:
            return False
    return True


def checkCross2():
    for i in range(N):
        if bingoBoard[N-1-i][i] != 0:
            return False
    return True


def checkBingo(bingoBoard): #빙고 체크
    bingo = 0

    for i in range(N):

        if checkRow(i):
            bingo += 1

        if checkCol(i):
            bingo += 1

    if checkCross1():
        bingo += 1
    
    if checkCross2():
        bingo += 1

    return bingo


def countThreeBingo(bingoBoard, callingNumber):
    for i in range(N*N):
        bingo = 0

        #숫자 지우기
        bingoBoard = findNum(bingoBoard, callingNumber[i])
       
        #빙고 개수 체크
        bingo = checkBingo(bingoBoard)
        if bingo >= 3:
            return i+1



if __name__ == "__main__":
    bingoBoard = []
    callingNumber = []
    
    for _ in range(N): #빙고판 입력
        line = list(map(int,input().split()))
        bingoBoard.append(line)
    
    for _ in range(N): #호출 숫자 입력
        line = list(map(int,input().split()))
        callingNumber.extend(line)
    
    print(countThreeBingo(bingoBoard, callingNumber))