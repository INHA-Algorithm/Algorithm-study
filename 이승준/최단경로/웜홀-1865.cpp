#include<iostream>
#include<vector>
#include<climits>
#include <cmath>

#define MAX 505


using namespace std;

void input();

void init();

void solve();

int edge[MAX][MAX];


int t, n, m, w;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        input();
        solve();
    }
}

void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][k] == INT_MAX || edge[k][j] == INT_MAX) continue;
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }
    bool isTImeMachine = false;

    for (int i = 1; i <= n; i++) {
        if (edge[i][i] != INT_MAX && edge[i][i] < 0) {
            isTImeMachine = true;
            break;
        }
    }
    if (isTImeMachine)cout << "YES\n";
    else cout << "NO\n";
}

void input() {
    init();
    cin >> n >> m >> w;
    int left, right, dist;

    for (int i = 1; i <= m; i++) {
        cin >> left >> right >> dist;
        edge[left][right] = min(edge[left][right], dist);
        edge[right][left] = min(edge[right][left], dist);
    }
    for (int i = 1; i <= w; i++) {
        cin >> left >> right >> dist;
        edge[left][right] = min(-dist, edge[left][right]);
    }
}

void init() {
    for (int i = 1; i <= 501; i++) {
        for (int j = 1; j <= 501; j++) {
            edge[i][j] = INT_MAX;
        }
    }
}