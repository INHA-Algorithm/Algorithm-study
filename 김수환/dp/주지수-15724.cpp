#include <bits/stdc++.h>

using namespace std;

#define MAX 1025

int n, m, k;

int graph[MAX][MAX];
int integrity[MAX][MAX];

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> k;
    integrity[0][0] = graph[0][0];
    for (int i = 1; i < m; i++) {
        integrity[0][i] = integrity[0][i - 1] + graph[0][i];
    }

    for (int i = 1; i < n; i++) {
        integrity[i][0] = integrity[i - 1][0] + graph[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            integrity[i][j] = integrity[i - 1][j] + integrity[i][j - 1] - integrity[i - 1][j - 1] + graph[i][j];
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout<<integrity[i][j] <<' ';
//        }cout << "\n";
//    }cout << endl;
}

void solve() {
    int a, b, c, d;
    while (k--) {
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        int ans = integrity[c][d];
        if (a > 0) ans -= integrity[a - 1][d];
        if (b > 0) ans -= integrity[c][b - 1];
        if (a > 0 && b > 0) ans += integrity[a - 1][b - 1];
        cout << ans <<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}