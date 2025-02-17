#제한
# 2초 메모리 128,000,000

#문제
# 팰린드롬 : 앞과 뒤에서 읽히는 문자열이 동일한 문자열
# 주어진 문자열에 최소한만 추가하면 팰린드롬을 구해라

#입력
# S는 알파벳 소문자로만 이루어져 있고, 길이는 최대 50

#출력
# 가장 짧은 팰린드롬의 길이 출력

#풀이
# 원래 배열의 앞부분을 제거하면서, 뒤집은 배열의 뒷부분을 제거하면서 비교 
# qwerty, ytrewq -> werty, ytrew

def findPalindromeLength(word, reversed_word):
     for i in range(len(word)):
        if word[i:] == reversed_word[:-i]:
            return len(word) + i


if __name__ == "__main__":
    word = input()
    reversed_word = word[::-1]

    print(findPalindromeLength(word, reversed_word))


    