#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>

#define MAX 200001

using namespace std;
typedef long long ll;
typedef map<int, int> umii;
typedef map<int, ll> umil;
int N, Q; // N: 배열 크기, Q: 질의 개수

vector<int> positions;
umii points;
umil left_dist_sum, left_point_sum, right_dist_sum, right_point_sum;

void input();

void solve();

void preprocess();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    preprocess();
    solve();
}

void solve() {
    int new_point;
    while (Q--) {
        cin >> new_point;
        int right_idx = upper_bound(positions.begin(), positions.end(), new_point) - positions.begin();

        if (right_idx == N) {
            cout << left_dist_sum[positions[N - 1]] +
                    abs((ll) (new_point - positions[N - 1])) * left_point_sum[positions[N - 1]] << "\n";
        } else if (right_idx == 0) {
            cout << right_dist_sum[positions[right_idx]] +
                    abs((ll) ( new_point - positions[right_idx])) * right_point_sum[positions[right_idx]] << "\n";
        } else {
            cout << left_dist_sum[positions[right_idx - 1]] + right_dist_sum[positions[right_idx]] +
                    abs((ll) ( new_point - positions[right_idx - 1])) * left_point_sum[positions[right_idx - 1]] +
                    abs((ll) (new_point - positions[right_idx])) * right_point_sum[positions[right_idx]] << "\n";
        }
    }
}

void preprocess() {
    int left_point = points[positions[0]];
    ll left_dist = 0;
    left_point_sum[positions[0]] = left_point;
    left_dist_sum[positions[0]] = 0;
    for (int i = 1; i < N; i++) {
        int cur = positions[i];
        int left = positions[i - 1];

        left_dist += (abs((ll) (cur - left)) * left_point);
        left_point += points[cur];
        left_dist_sum[cur] = left_dist;
        left_point_sum[cur] = left_point;
    }
    int right_point = points[positions[N - 1]];
    ll right_dist = 0;
    right_point_sum[positions[N - 1]] = right_point;
    right_dist_sum[positions[N - 1]] = 0;

    for (int i = N - 2; i >= 0; i--) {
        int cur = positions[i];
        int right = positions[i + 1];

        right_dist += (abs((ll) (cur - right)) * right_point);
        right_point += points[cur];
        right_dist_sum[cur] = right_dist;
        right_point_sum[cur] = right_point;
    }
}

void input() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int pos, point;
        cin >> point >> pos;
        positions.push_back(pos);
        points[pos] = point;
    }
    sort(positions.begin(), positions.end());

}
