#include <iostream>
#include <vector>
#include <cmath>

#define MAX 40001

using namespace std;

vector<int> weights(31);
vector<vector<int>> marble(31, vector<int>(MAX));

int n, m;

void solve(int idx, int value);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    solve(0, 0);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int target_marble;
        cin >> target_marble;
        (marble[n][target_marble]) ? cout << "Y " : cout << "N ";
    }
}

void solve(int idx, int weight) {
    if (weight > MAX || idx == n + 1) {
        // BASECASE: 비교할 무게의 최대값인 40001을 초과하거나, 무게추의 개수 N을 넘으면 return
        return;
    }
    if (marble[idx][weight])return;
    // MEMOIZATION: 동일한 무게추를 사용했을 때 같은 무게가 이미 나왔다면 다시 비교할 필요없음.
    marble[idx][weight] = true;
    solve(idx + 1, weight);
    solve(idx + 1, weight + weights[idx]);
    solve(idx + 1, abs(weight - weights[idx]));
}
