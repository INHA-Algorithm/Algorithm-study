#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, a, b, z, cnt;
long long K;
int parent[1000001];
vector<vector<int>> arr;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;

void reset() {
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x)return x;
    else {
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    reset();
    arr.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> z;
        Q.push({z, {0, i}});
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[a].emplace_back(b);
        arr[b].emplace_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (i == N)Q.push({0, {i, 1}});
        else Q.push({0, {i, i + 1}});
    }

    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int value = Q.top().first;
        Q.pop();
        auto it = find(arr[x].begin(), arr[x].end(), y);
        auto it_1 = find(arr[y].begin(), arr[y].end(), x);
        if (find(x) == find(y))continue;
        if (it != arr[x].end() || it_1 != arr[y].end())continue;
        Union(x, y);
        cnt++;
        K -= value;
    }

    if (M == 0 || M == 1) {
        cout << "YES";
    } else {
        if (K >= 0 && cnt == N) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

}