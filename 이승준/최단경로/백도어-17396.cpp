#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 100005
#define INF 10000000001

typedef long long  ll;
int n, m;

void input();

vector<ll> board(MAX, INF);
vector<pair<ll, ll>> edge[MAX];

bool seen[MAX];
bool visited[MAX];

void solve();

int main() {
    fastio();
    input();
    solve();
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> seen[i];
    }
    for (int i = 0; i < m; i++) {
        ll from, to, t;
        cin >> from >> to >> t;
        edge[from].push_back({t, to});
        edge[to].push_back({t, from});
    }
    for (int i = 0; i < n; i++) {
        sort(edge[i].begin(), edge[i].end());
    }
}

priority_queue<pair<ll, ll>> q;

/**
 * bfs를 하면 가장 빨리 도착하는게 최단거리?
 * q에 ndest를 넣고 이게 dp값보다 그거면 continue;
 */
void solve() {
    if (n == 1) {
        cout << 0;
        return;
    }
    board[0] = 0;
    seen[n - 1] = false;
    q.push({0, 0});
    visited[0] = true;




    // 1부터 N-1까지
    while (!q.empty()) {
        ll cur = q.top().second;
        ll dest = -q.top().first;
        q.pop();
        if (dest > board[cur])continue;
        visited[cur] = true;

        for (auto ele: edge[cur]) {
            ll next = ele.second;
            ll ndest = dest + ele.first;

            if (!visited[next] && board[next] > ndest && !seen[next]) {
                board[next] = ndest;
                q.push({-ndest, next});
            }
        }

    }

    if (board[n - 1] == INF) {
        cout << -1;
        return;
    }
    cout << board[n - 1];
}