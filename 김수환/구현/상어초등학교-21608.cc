#include <bits/stdc++.h>

using namespace std;

int n;
int rd[4] = {0, 0, 1, -1};
int cd[4] = {1, -1, 0, 0};

struct student {
    int num;
    int prefers[4];
    int preferPoint;
};

int points[5] = {0, 1, 10, 100, 1000};

bool oob(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= n);
}

struct seat {
    int r, c;
    int preferNum;
    int emptyNum;

    bool operator()(seat s1, seat s2) {
        if (s1.preferNum == s2.preferNum) {
            if (s1.emptyNum == s2.emptyNum) {
                if (s1.r == s2.r) {
                    return s1.c > s2.c;
                }
                return s1.r > s2.r;
            }
            return s1.emptyNum < s2.emptyNum;
        }
        return s1.preferNum < s2.preferNum;
    }
};

student classroom[21][21];

vector<student> students;


void init() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;
        student s = {num};
        for (int j = 0; j < 4; j++) {
            cin >> s.prefers[j];
        }
        students.emplace_back(s);
    }
}

seat calculateSeat(student st, int r, int c) {
    seat se = {r, c, 0, 0};
    for (int i = 0; i < 4; i++) {
        int nr = r + rd[i];
        int nc = c + cd[i];

        if (oob(nr, nc))continue;
        for (int p: st.prefers) {
            if (classroom[nr][nc].num == p) {
                se.preferNum++;
            }
        }
        if (!classroom[nr][nc].num) {
            se.emptyNum++;
        }
    }
    return se;
}

seat sit(student st) {
    priority_queue<seat, vector<seat>, seat> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (classroom[i][j].num)continue;
            pq.push(calculateSeat(st, i, j));
        }
    }
    seat se = pq.top();
    st.preferPoint = se.preferNum;

    classroom[se.r][se.c] = st;
    return se;
}

void calculatePreferPoint(seat se, student st) {
    for (int i = 0; i < 4; i++) {
        int nr = se.r + rd[i];
        int nc = se.c + cd[i];
        if (oob(nc, nr))continue;
        for (int prefer: classroom[nr][nc].prefers) {
            if (prefer == st.num) {
                classroom[nr][nc].preferPoint++;
            }
        }
    }
}

int calculateAnswer() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += points[classroom[i][j].preferPoint];
        }
    }
    return ans;
}

void solve() {
    for (auto st: students) {
        seat se = sit(st);
        calculatePreferPoint(se, st);
    }
    cout << calculateAnswer();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    init();
    solve();
}