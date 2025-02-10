#include <bits/stdc++.h>

#define INF 9901
using namespace std;
long long mem[100'001][2];
int n;


void init() {
    mem[0][0] = 1;
    mem[0][1] = 3;
    cin >> n;
}

void solve() {
    for (int i = 1; i < n; i++) {
        mem[i][0] = mem[i - 1][1] % INF;
        mem[i][1] = (mem[i - 1][1] * 2 + mem[i - 1][0]) % INF;
    }
    cout << mem[n - 1][1] % INF << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}