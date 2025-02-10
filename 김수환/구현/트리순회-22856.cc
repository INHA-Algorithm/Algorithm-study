#include <bits/stdc++.h>

using namespace std;

#define ROOT 1

int n;
struct node {
    int lc;
    int rc;
};
node nodes[100'001];
int ans, cnt;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v, lc, rc;
        cin >> v >> lc >> rc;
        nodes[v] = {lc, rc};
    }
}

void inOrder(int cur) {
    ans++;
    if (nodes[cur].lc != -1) {
        inOrder(nodes[cur].lc);
        ans++;
    }
    cnt++;
    if (cnt == n) {
        cout << ans-1;
        exit(0);
    }

    if (nodes[cur].rc != -1) {
        inOrder(nodes[cur].rc);
        ans++;
    }

}

void solve() {
    inOrder(ROOT);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}