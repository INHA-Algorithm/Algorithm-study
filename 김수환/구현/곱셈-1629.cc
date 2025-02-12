#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void init() {
    cin >> a >> b >> c;
}

long long dfs(int x, int y) {
    if (y == 1) {
        return x % c;
    }
    long long ret = dfs(x, y / 2);
    ret = (ret * ret) % c;
    return y % 2 ? (ret * x) % c : ret;
}

void solve() {
    cout << dfs(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}