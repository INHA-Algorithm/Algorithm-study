//
// Created by 김수환 on 2025/01/26.
//
#include <bits/stdc++.h>

using namespace std;
int t;

int arr[100'002][2];
int mem[100'002][2];
int n;

void init() {
    memset(arr, 0, sizeof(arr));
    memset(mem, 0, sizeof(mem));
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][1];
    }
    mem[0][0] = mem[0][1] = 0;
    mem[1][0] = arr[1][0];
    mem[1][1] = arr[1][1];
}


void solve() {
    for (int i = 2; i <= n; i++) {
        mem[i][0] = max(mem[i - 1][1] + arr[i][0], mem[i - 2][1] + arr[i][0]);
        mem[i][1] = max(mem[i - 1][0] + arr[i][1], mem[i - 2][0] + arr[i][1]);

    }

    cout << max(mem[n][0],mem[n][1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        init();
        solve();
    }

}