#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int n;
int mat[501][2];
int mem[501][501];
void init() {
    memset(mem,-1,sizeof mem);

    cin >> n;
    for(int i=0;i<n;i++){
        mem[i][i] = 0;
        cin >> mat[i][0] >> mat[i][1];
    }
}

int dp(int l, int r) {
    if (mem[l][r] != -1) return mem[l][r];

    mem[l][r] = INF;
    for (int k = l; k < r; k++) {
        mem[l][r] = min(mem[l][r], dp(l, k) + dp(k + 1, r) + mat[l][0] * mat[k][1] * mat[r][1]);
    }
    return mem[l][r];
}

void solve() {
    dp(0,n-1);
    cout << mem[0][n-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}