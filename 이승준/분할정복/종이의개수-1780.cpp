#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 2188

int n;
vector<vector<int>> m(MAX, vector<int>(MAX));
struct Paper {
    int zero = 0;
    int one = 0;
    int minusOne = 0;

    void toString(){
        cout << minusOne << "\n" << zero << "\n" << one << "\n";
    }
};
Paper ans;

void input();

void solve(int x, int y, int size);

int main() {
    fastio();
    input();
    solve(1, 1, n);
    ans.toString();
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
}

bool checkPaper(int y, int x, int size) {
    int first = m[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (first != m[i][j])return false;
        }
    }
    switch (first) {
        case -1 :
            ans.minusOne++;
            break;
        case 0:
            ans.zero++;
            break;
        case 1:
            ans.one++;
            break;
        default:
            cout << "this is error\n";
            break;
    }
    return true;
}

void solve(int y, int x, int size) {
    if (checkPaper(y, x, size))return;
    for (int ny = y; ny < y + size; ny += size/3) {
        for (int nx = x; nx < x + size; nx += size/3) {
            solve(ny, nx, size / 3);
        }
    }
}
//void update(int node, int index, int left, int right, int diff) {
//    if (index < left || index > right)return;
//
//    if (left != right) {
//        tree[node] += diff;
//        int mid = (left + right) / 2;
//        update(node * 2, index, left, mid, diff);
//        update(node * 2 + 1, index, mid + 1, right, diff);
//    } else if (left == right) {
//        if (left == index)tree[node] += diff;
//        return;
//    }
//}
