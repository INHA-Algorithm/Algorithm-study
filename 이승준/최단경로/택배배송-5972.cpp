#include<iostream>
#include<vector>
#include<queue>

#define MAX 50005
#define INF 987654321
#define EDGE pair<int,int>
using namespace std;

vector<vector<EDGE>> edges(MAX);
int dp[MAX];
int n, m;

void input();

void bfs();

int main() {
    input();
    bfs();
}

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (EDGE p: edges[cur]) {
            int next = p.first;
            int dist = p.second;

            if (dp[cur] + dist >= dp[next])continue;
            dp[next] = dp[cur] + dist;
            q.push(next);
        }
    }
    cout << dp[n];

}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    dp[1]=0;
    for (int i = 1; i <= m; i++) {
        int left, right, cost;
        cin >> left >> right >> cost;
        edges[left].push_back({right, cost});
        edges[right].push_back({left, cost});
    }
}
