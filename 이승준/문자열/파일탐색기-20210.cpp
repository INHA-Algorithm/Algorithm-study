#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cctype>

using namespace std;

enum TYPE {
    STRING,
    NUMBER
};
int n;
map<string, int> alphabetMap;
vector<vector<string>> v;

pair<string, int> checkZero(string s);

bool compare(vector<string> v1, vector<string> v2);

void init();

void input();

vector<string> answer;

int main() {
    // 알파벳 우선순위 값 설정.
    init();
    input();


    sort(v.begin(), v.end(), compare);
    int index = 0;
    for (auto lines: v) {


        string line = "";
        for (auto col: lines) {
            line += col;
        }
        cout << line << "\n";
    }
}


pair<string, int> checkZero(string s) {
    int ret = 0;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            ret++;
        } else break;
    }
    // 0 제거
    s = s.substr(ret);
    return {s, ret};
}

bool compare(vector<string> v1, vector<string> v2) {
    int len1 = v1.size();
    int len2 = v2.size();
    int minLen = min(len1, len2);
    for (int i = 0; i < minLen; i++) {
        //엘리먼트가 문자열인지 숫자인지 체크.
        TYPE t1 = (isalpha(v1[i][0])) ? STRING : NUMBER;
        TYPE t2 = (isalpha(v2[i][0])) ? STRING : NUMBER;
        string s1 = v1[i];
        string s2 = v2[i];

        if (t1 == t2) {
            if (t1 == STRING) {
                // 둘 다 문자열 일 때 둘의 값중 우선순위 값이 작은거가 먼저 옴.
                if (s1 != s2)return alphabetMap[s1] < alphabetMap[s2];
            } else {
                // 앞의 0을 자르고 0의 개수를 return
                auto p1 = checkZero(s1);
                auto p2 = checkZero(s2);
                if (p1.first.length() != p2.first.length()) {
                    return p1.first.length() < p2.first.length();
                }
                int minNumLen = min(p1.first.length(), p2.first.length());
                string n1 = p1.first;
                string n2 = p2.first;

                for (int j = 0; j < minNumLen; j++) {
                    //두 값중 작을때만 return
                    if (n1 != n2)return n1 < n2;
                }
                // 10진수 값이 같을 땐 0의 개수가 더 적은게 앞으로 오도록.
                if (p1.second != p2.second) return p1.second < p2.second;
            }
        } else {
            // 두 개의 타입이 다를 때
            return t1 == NUMBER;
        }
    }
    // minLen까지의 비교가 동일할 때 더 길이가 짧은게 앞으로 옴.
    return len1 < len2;
}


void init() {
    int index = 1;
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        alphabetMap[string(1, ch)] = index++;     // 대문자 삽입
        alphabetMap[string(1, ch + 32)] = index++; // 소문자 삽입 (대문자 + 32 = 소문자)
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string buffer;
        vector<string> line;
        for (auto c: str) {
            if (isalpha(c)) {
                // 문자열은 바로 삽입
                if (!buffer.empty())line.push_back(buffer);
                buffer = "";
                line.push_back(string(1, c));
            } else {
                buffer += c;
            }
        }
        if (!buffer.empty())line.push_back(buffer);
        v.push_back(line);
    }
}