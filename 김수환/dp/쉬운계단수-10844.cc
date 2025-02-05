#include <bits/stdc++.h>

#define MAX 1000000000

using namespace std;

long long stepN[101][10];

int n;
long long ans;

void init() {
    for (int i = 1; i < 10; i++) {
        stepN[1][i] = 1;
    }
    cin >> n;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) stepN[i][0] = (stepN[i - 1][1]) % MAX;
            else if (j == 9) stepN[i][9] = (stepN[i - 1][8]) % MAX;
            else stepN[i][j] = (stepN[i - 1][j - 1] + stepN[i - 1][j + 1]) % MAX;
        }
    }

}

void solve() {
    for (int i = 0; i < 10; i++) {
        ans += stepN[n][i];
        ans %= MAX;
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