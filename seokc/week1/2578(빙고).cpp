//
// Created by 김석찬 on 2025/01/20.
//

#include<iostream>
#include <map>

using namespace std;

int arr[6][6];
int row[6];
int col[6];
bool Left, Right;

int cnt;
map<int, pair<int, int>> m;

void findBingo(int num) {
    int x = m[num].first;
    int y = m[num].second;
    arr[y][x] = true;
    bool ans = true;

    for (int i = 0; i < 5; i++) {
        if (i == x)continue;
        if (!arr[y][i] || row[y]) {
            ans = false;
            break;
        }
    }
    if (ans && !row[y]) {
        cnt++;
        row[y] = true;
    }
    ans = true;
    for (int i = 0; i < 5; i++) {
        if (i == y)continue;
        if (!arr[i][x] || col[x]) {
            ans = false;
            break;
        }
    }
    if (ans && !col[x]) {
        col[x] = true;
        cnt++;
    }
    ans = true;
    for (int i = 0; i < 5; i++) {
        if ((x == i && y == i))continue;
        if (!arr[i][i] || Left) {
            ans = false;
            break;
        }
    }
    if (ans && !Left) {
        Left = true;
        cnt++;
    }
    ans = true;
    for (int i = 0; i < 5; i++) {
        if ((x == 4 - i && y == i))continue;
        if (!arr[i][4 - i] || Right) {
            ans = false;
            break;
        }
    }
    if (ans && !Right) {
        Right = true;
        cnt++;
    }

}

int main() {
    int num;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> num;
            m[num] = {j, i};
        }
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> num;
            findBingo(num);
            if (cnt >= 3) {
                cout << (j + 1) + (5 * i);
                return 0;
            }
        }
    }
}