#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2001];
int mem[2001][2001];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int dp(int s, int e, int cnt) {
    if (s > e) return 0;
    if (mem[s][e]) return mem[s][e];
    return mem[s][e] = max(
            cnt * arr[s] + dp(s + 1, e, cnt + 1),
            cnt * arr[e] + dp(s, e - 1, cnt + 1)
            );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    cout << dp(0, n - 1, 1);
}
