#include<iostream>
#include<string>
#include<vector>

using namespace std;

string cmd;
int len;
vector<char> v;

void input();

bool checkPalindrome() {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        if (v[left] != v[right])return false;
        left++;
        right--;
    }
    return true;
}

bool customPalindrome(int left, int right) {
    while (left <= right) {

        if (v[left] != v[right])return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    input();

    while (!checkPalindrome()) {
        int len = v.size();
        v.push_back(v[0]);
        for (int i = 0; i < len; i++) {
            //앞에서부터 하나씩 넣어보면서 펠린드롬인지 체크
            // abcd□ , □ = a  -> □ = b  -> □ = c -> □ -> d
            //
            v[v.size() - 1] = v[i];
            if (customPalindrome(i, v.size() - 1))break;
        }
    }
    cout << v.size();
    return 0;

}

void input() {
    cin >> cmd;

    for (char c: cmd) {
        v.push_back(c);
    }
}