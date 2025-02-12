#include <iostream>
#include <vector>

using namespace std;
int n, m;
int numbers[8];
bool used[9];

void print() {
    for (int i = 0; i < m; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
}

void solve(int len) {
    if (len == m) {
        print();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i])continue;
        //before
        used[i] = true;
        numbers[len] = i;

        solve(len + 1);

        //after
        used[i] = false;
        numbers[len] = 0;
    }

}

int main() {
    cin >> n >> m;
    solve(0);
}