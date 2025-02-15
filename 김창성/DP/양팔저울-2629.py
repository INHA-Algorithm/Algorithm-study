#제한
# 1초, 메모리 512,000,000

#문제
# 추와 구슬이 주어졌을 때, 
# 양팔저울에 구슬과 추를 올려 수평을 맞출 수 있는지 판단해라 

#입력
# 0 < 추의 개수 <= 30, 0 < 추의 무게 <= 500
# 0 < 구슬의 개수 <= 7, 0 < 구슬의 무게 <= 40,000

#출력
# 구슬의 무게를 확인할 수 있으면 Y, 없으면 N 출력



def dp(N, weights, totalWeight, marble):
    balance = [False]*40001
    balance[0] = True
    
    for i in range(N):
        for j in range(totalWeight,-1,-1):
            if balance[j]:
                balance[j + weights[i]] = True
        for j in range(0,totalWeight):
            if balance[j]:
                balance[abs(j - weights[i])] = True
        
    if balance[marble]:
        return "Y"
    return "N"

if __name__ == "__main__":
    N = int(input())
    weights = list(map(int,input().split()))
    M = int(input())
    marbles = list(map(int,input().split()))

    totalWeight = sum(weights)

    for marble in marbles:
        print(dp(N, weights, totalWeight, marble),end=" ")
    