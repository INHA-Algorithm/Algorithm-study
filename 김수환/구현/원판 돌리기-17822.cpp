#include <bits/stdc++.h>

#define MAX 51
using namespace std;

int N, M, T;

int mod(int x, int n) {
    int y = x % n;
    return y < 0 ? y + n : y;
}

class Circle {
public:
    int arr[MAX]{};
    int s;

    Circle() {
        s = 0;
        memset(arr, 0, sizeof arr);
    }

    void set(int i, int v) {
        arr[getIdx(i)] = v;
    }

    void pm(int i, int v) {
        v > 0 ? arr[getIdx(i)]++ : arr[getIdx(i)]--;
    }

    void rotate(int d, int k) {
        if (d) {
            s = mod(s + k, M);
        } else {
            s = mod(s - k, M);
        }
    }

    int getIdx(int i) {
        return mod(s + i, M);
    }

    int at(int i) {
        return arr[getIdx(i)];
    }

    void erase(int i) {
        arr[getIdx(i)] = 0;
    }
};


Circle circles[MAX];

void update() {
    set<pair<int, int>> targets;
    double mean = 0;
    double cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!circles[i].at(j)) continue;

            cnt++;
            mean += circles[i].at(j);

            if (circles[i].at(j) == circles[i].at(j - 1)) {
                targets.insert({i, j});
                targets.insert({i, j - 1});
            }
            if (i == 0)continue;
            if (circles[i].at(j) == circles[i - 1].at(j)) {
                targets.insert({i, j});
                targets.insert({i - 1, j});
            }

        }
    }

    if (targets.empty()) {
        mean /= cnt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!circles[i].at(j)) continue;
                if (circles[i].at(j) < mean) {
                    circles[i].pm(j, 1);
                } else if (circles[i].at(j) > mean) {
                    circles[i].pm(j, -1);
                }
            }
        }
    }

    for (auto p: targets) {
        circles[p.first].erase(p.second);
    }
}

void init() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int v;
            cin >> v;
            circles[i].set(j, v);
        }
    }
}


void solve() {
    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;
        for (int i = x; i <= N; i += x) {
            circles[i - 1].rotate(d, k);
        }
        update();
    }


    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += circles[i].at(j);
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