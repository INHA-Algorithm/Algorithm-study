//
// Created by 김수환 on 2025/01/22.
//
#include <bits/stdc++.h>

using namespace std;

int bingo[13];
pair<int, int> loc[26];

void init() {
    int a;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a;
            loc[a] = {i, j};
        }
    }
}

void solve() {
    int a;
    for (int i = 0; i < 25; i++) {
        cin >> a;
        if (loc[a].first == loc[a].second) { // \ 대각선
            bingo[10] += 1;
        }
        if (loc[a].first + loc[a].second == 4) { // / 대각선
            bingo[11] += 1;
        }
        bingo[loc[a].first] += 1; // - 수평선
        bingo[loc[a].second + 5] += 1; // | 수직선
        int cnt = 0;
        for (int v: bingo) {

            if (v >= 5) {
                cnt++;
            }
            if (cnt == 3) {
                cout << i + 1;
                return;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}