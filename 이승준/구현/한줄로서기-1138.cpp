#include<iostream>
#include<vector>

using namespace std;
int n;
vector<int> height_memory(11);
vector<bool> used(11, false);
vector<int> line(11);

void input();

bool check();

void solve(int len);

int main() {
    input();
    solve(1);
}

void solve(int len) {
    if (len == n + 1) {
        if (check()) {
            for (int i = 1; i <= n; i++) {
                cout << line[i] << " ";
            }
            cout << "\n";
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i])continue;
        used[i] = true; // 해당 키를 가진 사람을 줄 세움
        line[len] = i; // 실제 줄에 넣음.
        solve(len + 1);
        used[i] = false;
        line[len] = 0;  //초기화
    }
}

void input() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> height_memory[i];
    }
}

bool check() {
    vector<bool> is_present(11, false);
    vector<int> check_left_person(11, 0);

    for (int i = 1; i <= n; i++) {
        int person_height = line[i];
        is_present[person_height] = true;

        // 나보다 작고 아직 등장안한 사람 => 내 자신이 다른사람의 내 왼쪽에 있는 큰 사람에 해당
        for (int j = 1; j < person_height; j++) {
            if (is_present[j])continue;
            check_left_person[j]++;
        }
    }
    for (int len = 1; len <= n; len++) {
        if (check_left_person[len] != height_memory[len])return false;
    }
    return true;
}