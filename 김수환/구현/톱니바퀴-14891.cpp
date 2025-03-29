#include <bits/stdc++.h>

#define N 4
#define L 6
#define R 2
using namespace std;


deque<bool> wheels[N];

int k;
vector<pair<int, bool>> cmd; // 시계 1, 반시계 0
int ans;
int chk[N]; // -1 가만히 , 1 시계, 반시계 0

void rot(deque<bool> *w, bool dir) {
    if (dir) { // 시계
        w->push_front(w->back());
        w->pop_back();
    } else { // 반시계
        w->push_back(w->front());
        w->pop_front();
    }
}


void chk_left(int idx, bool dir) {
    if (!idx)return; // 가장 왼쪽
    if (wheels[idx][L] == wheels[idx - 1][R])return;
    chk[idx - 1] = !dir;
    chk_left(idx - 1, !dir);
}

void chk_right(int idx, bool dir) {
    if (idx == N - 1)return; // 가장 오른쪽
    if (wheels[idx][R] == wheels[idx + 1][L])return;
    chk[idx + 1] = !dir;
    chk_right(idx + 1, !dir);
}

void init() {
    for (auto &wheel: wheels) {
        string input;
        cin >> input;
        for (char c: input) {
            wheel.push_back(c - '0');
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cmd.emplace_back(a - 1, (b == 1));
    }
}

void solve() {
    for (auto c: cmd) {
        memset(chk, -1, sizeof chk);
        vector<pair<int, bool>> rw;

        chk[c.first] = c.second;
        chk_left(c.first, c.second);
        chk_right(c.first, c.second);
        for (int i = 0; i < N; i++) {
            if (chk[i] == -1)continue;
            rw.emplace_back(i, chk[i]);
        }

        for (auto r: rw) {
            rot(&wheels[r.first], r.second);
        }
    }

    for (int i = 0; i < 4; i++) {
        ans |= (wheels[i][0] << i);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
