#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

ll n, st, ed;

struct Meeting {
    ll start_time;
    ll end_time;
    // 생성자
    Meeting(ll start_time, ll end_time) {
        this->start_time = start_time;
        this->end_time = end_time;
    }
};

bool compare(Meeting a, Meeting b) {
    if (a.end_time!= b.end_time)return a.end_time < b.end_time;
    return a.start_time < b.start_time;
}

vector<Meeting> v;

int main() {
    cin >> n;
    int len = n;
    while (len--) {
        cin >> st >> ed;

        v.emplace_back(st, ed);
    }
    sort(v.begin(), v.end(), compare);

    int ans = 0;
    ll last_end_time = 0;

    for (auto p: v) {
        if (p.start_time < last_end_time) continue;
        last_end_time = p.end_time;
        ans++;
    }
    cout << ans;
}