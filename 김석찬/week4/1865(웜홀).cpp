#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

vector<pair<pair<int, int>, int>> v;
int dist[501];

void sol(int n) {
    for (int i = 0; i < n; i++) {
        for (int t = 0; t < v.size(); t++) {
            int b = v[t].first.first;
            int a = v[t].first.second;
            int cost = v[t].second;

            if (dist[b] + cost < dist[a]) dist[a] = dist[b] + cost;
        }
    }

    for (int t = 0; t < v.size(); t++) {
        int b = v[t].first.first;
        int a = v[t].first.second;
        int cost = v[t].second;
        if (dist[b] + cost < dist[a]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

}


int main() {

    int tc;
    cin >> tc;

    while (tc--) {
        v.clear();
        int n, m, w;
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) dist[i] = INF;

        int b, a, cost;
        for (int i = 0; i < m; i++) {

            cin >> b >> a >> cost;
            v.push_back({{b, a}, cost});
            v.push_back({{a, b}, cost});
        }
        for (int i = 0; i < w; i++) {
            cin >> b >> a >> cost;
            v.push_back({{b, a}, -cost});
        }

        sol(n);
    }


    return 0;
}