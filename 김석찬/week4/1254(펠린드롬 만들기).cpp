//
// Created by 김석찬 on 2025/02/13.
//

#include <iostream>
#include <queue>

using namespace std;

string s;

int sol() {
    int size = s.length();
    int backIdx, frontIdx;

    while (1) {
        if (size % 2 == 0) { // 짝수일 경우
            frontIdx = size / 2 - 1;
            backIdx = size / 2;
        } else { // 홀수일 경우
            frontIdx = size / 2 - 1;
            backIdx = size / 2 + 1;
        }
        while (backIdx <= s.length() - 1) {
            if (s[frontIdx] == s[backIdx]) {
                frontIdx--;
                backIdx++;
            } else {
                break;
            }
        }
        if (backIdx > s.length() - 1) { // 끝까지 탐색을 완료 했다는것
            return size;
        }
        size++;
    }
}

int main() {
    cin >> s;
    cout<<sol();

}