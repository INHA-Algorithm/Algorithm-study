#제한
# 2초, 메모리 512,000,000

#문제
# 회의가 겹치지 않게 하면서 
# 회의실을 사용할 수 있는 최대 개수를 구해라

#입력
#  1 ≤ 회의의 수 N ≤ 100,000
#  0 <= 시작 시간, 끝나는 시간 < 2^31-1 

#출력
# 최대 회의 개수

#풀이
# 1. 빨리 끝나는 회의부터 정렬
# 2. 끝나는 시간이 같다면 더 빠른시간부터 넣기

def planSchedules(schedules):
    count = 1
    end = schedules[0][1]

    for s, e in schedules[1:]:
        if end <= s:
            end = e
            count += 1

    return count


if __name__ == "__main__":
    N = int(input())
    schedules = []

    for _ in range(N):
        start, end = map(int,input().split())
        schedules.append((start, end))

    schedules.sort(key=lambda x:(x[1], x[0]))

    print(planSchedules(schedules))
    




