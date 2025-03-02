#제한
# 2초, 메모리 128,000,000

#문제
# 0과 1로만 이루어진 행렬 A를 행렬 B로 바꾸는 데 
# 필요한 연산 횟수의 최소값을 구하는 프로그램을 작성해라
# 연산: 3x3크기의 부분 행렬에 있는 모든 원소 뒤집기 0 -> 1

#입력
# 1<= N, M <= 50

#출력
#연산의 최소값, 변환할 수 없다면 -1

def flip_3x3(matrix, x, y):
    for i in range(3):
        for j in range(3):
            matrix[x+i][y+j] = 1 - matrix[x+i][y+j]  # 0 -> 1, 1 -> 0

def count_change(N, M, primary, result):
    count = 0
    
    if primary == result:
        return 0

    if N < 3 or M < 3:
        return -1
    
    for i in range(N-2):
        for j in range(M-2):
            if primary[i][j] != result[i][j]:
                flip_3x3(primary, i, j)
                count += 1

    if primary == result:
        return count
    else:
        return -1

if __name__ == "__main__":
    N, M = map(int, input().split())
    primary = [list(map(int, input().strip())) for _ in range(N)]
    result = [list(map(int, input().strip())) for _ in range(N)]
    
    print(count_change(N, M, primary, result))

