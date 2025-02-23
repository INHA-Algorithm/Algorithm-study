#제한
# 2초, 메모리 128,000,000

#문제
# 자기보다 큰 사람이 왼쪽에 몇명 있었는지만 기억할 때,
# 줄을 세워라

#입력
# 0 < 사람 수 N, 왼쪽에 있는 키 큰 사람의 수 <= 10
# 키: 1~N

#풀이
# 1,2,3 .. N을 배치
# 숫자가 큰 값, 즉 키 큰 사람 0인것부터 배치

def placeBack1Seat(line, num):
    for i in range(N-num):
        line[-(i+1)] = line[-(i+2)]


def dicideLine(N, order):
    line = [0]*N

    for i in range(N):
        current = N-i

        placeBack1Seat(line,order[i]+1) #정해진 위치부터 한칸씩 미루기
        line[order[i]] = current

    return ' '.join(map(str,line))

if __name__ == "__main__":
    N = int(input())
    order = list(map(int,input().split()))

    print(dicideLine(N, order[::-1]))
    

