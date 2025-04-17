#include <bits/stdc++.h>

#define ll long long
using namespace std;


struct edge {
    int dest;
    ll dist;
};

struct cmp {
    bool operator()(edge e1, edge e2) {
        return e1.dist > e2.dist;
    }
};


vector<edge> edges[100'001];


int n, m;
bool visible[100'001];
ll dist[100'001];

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> visible[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        if (a != n - 1 && visible[a])continue;
        if (b != n - 1 && visible[b])continue;
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }
    for (int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
    }
}

void solve() {
    priority_queue<edge, vector<edge>, cmp> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        edge edge = pq.top();
        pq.pop();
        int cur = edge.dest;
        ll cd = edge.dist;
        if (dist[cur] < cd) continue;
        if (cur == n - 1) {
            cout << cd;
            return;
        }
        for (auto e: edges[cur]) {
            if (dist[e.dest] <= cd + e.dist) continue;
            dist[e.dest] = cd + e.dist;
            pq.push({e.dest, cd + e.dist});
        }
    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}
