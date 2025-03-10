#제한
# 2초, 메모리 512,000,000

#문제
# 소리가 주어질 때, 방 안의 오리 수를 구해라
# 오리는 quack 순서로 운다.
# "quqacukqauackck"는 두 오리가 울었다고 볼 수 있다.\

#입력
# 5 <= 소리의 길이 <= 2500

#출력
# 오리 수를 출력하라, 소리가가 올바르지 않다면 -1

#풀이
# quack 순서로 오리 한마리씩 체크
# 마지막에 한번에 체크해야 함, quack이 안채워질 수도 있기 때문
# 안채워지면 -1반환

from collections import deque

def count_duck(cry):
    count_duck = 0

    correct_cry = "quack"
    check_array = [False]*len(cry)
    one_duck_check = deque()

    if len(cry) % 5 != 0:
        return -1

    while True:
        count_corrent_cry = 0

        for i in range(len(cry)): #q부터 시작하지 않는것 고려
            if check_array[i]==False and cry[i] == correct_cry[count_corrent_cry % 5]:
                one_duck_check.append(i)
                count_corrent_cry += 1
        
        if len(one_duck_check) == 0:
            return -1

        if len(one_duck_check)%5 == 0:
            while one_duck_check:
                check_array[one_duck_check.pop()] = True
            count_duck += 1
        else:
            return -1
    
        if False not in check_array:
            return count_duck


if __name__ == "__main__":
    cry = input()

    print(count_duck(cry))