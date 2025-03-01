#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 51
int n, m;
bool origin[MAX_SIZE][MAX_SIZE];
bool target[MAX_SIZE][MAX_SIZE];
int ans;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            origin[i][j] = (input[j] == '1');
        }
    }

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            target[i][j] = (input[j] == '1');
        }
    }

}

void solve() {
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (origin[i][j] == target[i][j])
                continue;

            for (int k = i; k <= i + 2; k++) {
                for (int l = j; l <= j + 2; l++) {
                    origin[k][l] = !origin[k][l];
                }
            }
            ans++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (origin[i][j] ^ target[i][j]) {
                cout << -1 << '\n';
                return;
            }
        }
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