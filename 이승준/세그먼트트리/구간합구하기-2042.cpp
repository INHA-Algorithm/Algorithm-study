#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 1000000
int n, m, k;

void input();

void solve();

ll build(int node, int left, int right);

void update(int node, int index, int left, int right, ll diff);

ll sum(int node, int left, int right, int start, int end);

vector<ll> v;
vector<ll> tree(4 * MAX);

int main() {
    fastio();
    input();
    solve();
}

void input() {
    cin >> n >> m >> k;
    ll value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }
    build(1, 0, n - 1);
}

void solve() {
    ll cmd, b, c;
    for (int i = 0; i < m + k; i++) {
        cin >> cmd >> b >> c;
        ll diff = c - v[b - 1];
        switch (cmd) {
            case 1:
                // update  b를 c로 변경
                v[b - 1] = c;
                update(1, b - 1, 0, n - 1, diff);
                break;
            case 2:
                cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
                break;
        }
    }
}

ll build(int node, int left, int right) {
    if (left == right) {
        return tree[node] = v[left];
    }
    int mid = (left + right) / 2;
    ll left_value = build(node * 2, left, mid);
    ll right_value = build(node * 2 + 1, mid + 1, right);
    return tree[node] = left_value + right_value;
}

void update(int node, int index, int left, int right, ll diff) {
    if (index < left || index > right)return;

    if (left != right) {
        tree[node] += diff;
        int mid = (left + right) / 2;
        update(node * 2, index, left, mid, diff);
        update(node * 2 + 1, index, mid + 1, right, diff);
    } else if (left == right) {
        if (left == index)tree[node] += diff;
    }
}

// left,right 해당 노드의 반경 start,end 구하려는 구간합 반경
ll sum(int node, int left, int right, int start, int end) {
    if (start > right || end < left)return 0;
    if (left >= start && right <= end) return tree[node];

    int mid = (left + right) / 2;
    ll left_value = sum(node * 2, left, mid, start, end);
    ll right_value = sum(node * 2 + 1, mid + 1, right, start, end);
    return left_value + right_value;
}