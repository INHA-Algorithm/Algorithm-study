#include<iostream>
#include<map>

using namespace std;
int n = 5;
int bingo[6][6];
int number[6][6];
map<int, pair<int, int>> m;
bool Left, Right;

int main() {
    int input = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> input;
            number[i][j] = input;
            m[input] = {i, j};
        }
    }
    int cmd;
    int bingo_cnt = 0;
    // 숫자는 5*(i-1)+j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cmd;
            int y = m[cmd].first;
            int x = m[cmd].second;
            bingo[y][x] = true;

            bool is_row_bingo = true;
            bool is_col_bingo = true;
            for (int k = 1; k <= 5; k++) {
                if (!bingo[k][x])is_col_bingo = false;
                if (!bingo[y][k])is_row_bingo = false;
            }
            if (is_row_bingo) {
                bingo_cnt++;
            }
            if (is_col_bingo) {
                bingo_cnt++;
            }
            bool left_diagonal = true;
            for (int k = 1; k <= 5; k++) {
                if (!bingo[k][k])left_diagonal = false;
            }
            if (left_diagonal&&!Left) {
                Left = true;
                bingo_cnt++;
            }
            bool right_diagonal = true;

            for (int k = 1; k <= 5; k++) {
                if (!bingo[k][n - k + 1])right_diagonal = false;
            }
            if (right_diagonal&&!Right) {
                Right=true;
                bingo_cnt++;
            }

            if (bingo_cnt >= 3) {
                cout << 5 * (i - 1) + j << endl;
                exit(0);
            }
        }
    }
}
