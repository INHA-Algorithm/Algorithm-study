#제한
# 3초, 메모리 1024,000,000

#문제
# 수직 선 위에 놓인 N마을에서 위치를 구한다.
# a(x2-x1)로 거리를 구할 때, 
# 각 후보 장소에 대한 누적 거리의 합을 구해라
# a: 사람 수, x2:마을 위치, x1:모임 위치

#입력
# 1 ≤ 마을의 수 N, 모임 위치 개수 Q ≤ 200 000
# 1 ≤ 사람 수 ai ≤ 1 000
# −10^9 ≤ x2, x1 ≤ 10^9

#출력
# 후보 장소에 대한 누적 거리 합을 구해라

#풀이
# 마을에서 모임을 한다고 가정하고 계산한 뒤,
# 모임장소와 위치 차이 구하기


if __name__ == "__main__":
    N, Q = map(int,input().split())
    towns = []
    
    for _ in range(N):
        people, position = map(int,input().split())
        towns.append((position, people))
    towns.sort()
    
    #가장 왼쪽으로 모였을 때
    population = [-sum(towns[i][1] for i in range(N))] 
    for i in range(N):
        # 오른쪽, 왼쪽에서 해당 지점에서 올때 고려 == *2
        population.append(population[-1] + 2*towns[i][1]) 
    
    #가장 왼쪽에서 모였을 때
    umulative_sum = [sum((towns[i][0]-towns[0][0])*towns[i][1] for i in range(1,N))]
    for i in range(N-1):
        umulative_sum.append(umulative_sum[-1] + (towns[i+1][0]-towns[i][0])*population[i+1])
    

    for _ in range(Q):
        meeting_position = int(input())
        index = 0

        for i in range(N):
            if meeting_position < towns[i][0]:
                index = i
                break
        
        print(abs(umulative_sum[index] + (meeting_position-towns[index][0])*population[index]))

                  


    