#include<iostream>

using namespace std;

int N;
int ans[3];
int arr[2200][2200];

void sol(int x, int y, int size) {
    int chk = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[y][x] != arr[i][j]) {
                chk = false;
                break;
            }
        }
    }

    if (!chk) {
        int nxtSize = size / 3;
        sol(x, y, nxtSize);
        sol(x + nxtSize, y, nxtSize);
        sol(x + nxtSize * 2, y, nxtSize);
        sol(x, y + nxtSize, nxtSize);
        sol(x + nxtSize, y + nxtSize, nxtSize);
        sol(x + nxtSize * 2, y + nxtSize, nxtSize);
        sol(x, y + 2 * nxtSize, nxtSize);
        sol(x + nxtSize, y + 2 * nxtSize, nxtSize);
        sol(x + nxtSize * 2, y + 2 * nxtSize, nxtSize);
    } else {
        ans[arr[y][x] + 1]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    sol(0, 0, N);
    for (auto i: ans) {
        cout << i << '\n';
    }

}