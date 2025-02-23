#제한
# 1초, 메모리 512,000,000

#문제
# 정렬해서 출력해라
# 1. 알파벳 대소문자 숫자로 이루어져있다
# 2. 1, A, a 순서를 따른다
# 3. 숫자는 묶어서 비교한다. a123a 일때 123으로 처리
# 4. 숫자는 십진법으로 읽어서 작은 것이 앞에 온다
# 5. 같은 값의 숫자열에선 0의 개수가 적은 것이 앞에 온다.

#입력
# 2 ≤ 문자열 개수수 N ≤ 10,000
# 길이 ≤ 100

#출력
# 정렬 결과 출력

import re
from functools import cmp_to_key

def return_value(x, y):
    if x < y:
        return -1
    elif x == y:
        return 0
    else:
        return 1

def comparator(a, b):
    parsed_a = re.findall('[a-zA-Z]|\d+',a)
    parsed_b = re.findall('[a-zA-Z]|\d+',b)

    for i in range(min(len(parsed_a), len(parsed_b))):
        x, y = parsed_a[i], parsed_b[i]

        if x != y:
            #print("달라")
            if x.isdigit() and y.isdigit():
                #print("둘다 숫자")
                if int(x) == int(y):
                    return return_value(len(x),len(y))
                else:
                    return return_value(int(x),int(y))
            elif x.isdigit() != y.isdigit(): #하나라도 숫자가 아닐때
                return return_value(y.isdigit(), x.isdigit()) #True 1, False 0
            elif not x.isdigit() and not y.isdigit():
                if x.lower() == y.lower():
                    return return_value(x, y)
                return return_value(x.lower(), y.lower())

    #return return_value(len(parsed_a),len(parsed_b))
    # -1 a가 앞에  1 b가 앞에, 순서 유지
    


if __name__ == "__main__":
    N = int(input())
    array = [""]*N

    for i in range(N):
        array[i] = input()

    array.sort(key=cmp_to_key(comparator))
    for i in array:
        print(i)