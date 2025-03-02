#제한
# 2초, 256,000,000

#문제
# 종이의 N×N크기의 행렬의 각 칸에 -1,0,1 중 하나가 저장되어 있다.
# 종이에 같은 수로 되어 있다면 그대로 사용한다
# 아닌 경우 같은 크기의 종이 9개로 자른다.
# 마지막에 -1,0,1 수로만 채워진 종이의 개수를 각각 구해라

#입력
# 1 ≤ N ≤ 3^7
# N = 3^k

#출력
# 첫째 줄에 -1, 둘째 줄에 0, 셋째 줄에 1로만 채워진 종이의 개수를 출력

#풀이

total = [0,0,0]

def checkSame(x, y, size, paper):
    check_num = paper[x][y]

    for i in range(size):
        for j in range(size):
            if paper[x+i][y+j] != check_num:
                return None
    return check_num


def cutPaper(x, y, size, paper): 
    result = checkSame(x,y,size,paper)

    if result is not None:
        total[result] += 1
        return
    
    size = size//3
    for i in range(3):
        for j in range(3):  
            cutPaper(x+size*i,y+size*j,size,paper)       
          

if __name__ == "__main__":
    N = int(input())
    paper = []

    for _ in range(N):
        paper.append(list(map(int,input().split())))

    cutPaper(0,0,N, paper)
    
    print(total[-1])
    print(total[0])
    print(total[1])