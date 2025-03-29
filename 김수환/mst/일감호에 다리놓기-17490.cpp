#include <bits/stdc++.h>

using namespace std;

int n, m;
long long k, ans;
int rock[1'000'002];
vector<int> disable;

void init() {
    cin >> n >> m >> k;


    for (int i = 1; i <= n; i++) {
        cin >> rock[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if ((a == n && b == 1) || (b == n && a == 1))
            disable.push_back(n);
        else
            disable.push_back(min(a, b));
    }
    sort(disable.begin(), disable.end());
}

int cal(int s, int e) {
    int cost = INT_MAX;
    for (int i = s; i <= e; i++) {
        cost = min(cost, rock[i]);
    }
    return cost;
}

void solve() {
    if (m <= 1) {
        cout << "YES\n";
        exit(0);
    }
    int prev = 1;

    for (int cur : disable) {
        int mc = cal(prev, cur);

        if (cur == disable.front()) {
            mc = min(mc, cal(disable.back() + 1, n));
        }

        ans += mc;
        prev = cur + 1;
    }

    cout << (ans <= k ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}
