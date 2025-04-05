#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>
#include<deque>
#include<cmath>
using namespace std;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 8;
vector<deque<int>> v(4);
int n, k;

void input();

void solve();

int main() {
    fastio();
    input();
    solve();
}

void input() {
    for (int i = 0; i < 4; i++) {
        string cmd;
        cin >> cmd;
        for (char c: cmd) {
            v[i].push_back(c - '0');
        }
    }
}

void turn(int idx, int dir) {
    int len = v[idx].size();
    if (dir == 1) {
        int num = v[idx].back();
        v[idx].push_front(num);
        v[idx].pop_back();
    } else {
        int num = v[idx].front();
        v[idx].push_back(num);
        v[idx].pop_front();
    }
}

void solve() {
    cin >> k;
    while (k--) {
        int idx, dir;
        cin >> idx >> dir;
        idx--;
        int left_dir = dir;
        int right_dir = dir;
        vector<pair<int, int>> temp;
        temp.push_back({idx, dir});
        for (int i = idx; i >= 1; i--) {
            if (v[i][6] != v[i - 1][2]) {
                temp.push_back({i - 1, left_dir *= -1});
            }else break;
        }
        for (int i = idx; i < 3; i++) {
            if (v[i][2] != v[i + 1][6]) {
                temp.push_back({i + 1, right_dir *= -1});
            }else break;
        }
        for (auto a: temp) {
            turn(a.first, a.second);
        }
    }
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        if (v[i][0] == 1)ans += (int) pow(2, i);
    }
    cout << ans;
}