#include <bits/stdc++.h>

using namespace std;

#define MOD 10'007

int n;

int solve(int v, int ans) {
    if (v <= 4) {
        return v * ans % MOD;
    }
    return solve(v - 3, ans * 3 % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << solve(n,1);
}