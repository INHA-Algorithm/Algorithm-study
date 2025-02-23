#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
int MAX = -1;
long long n, m;
vector<int> woods;

void input();
long long sawing();
void solve();

vector<int> value = {1, 2, 3, 4, 5, 6, 8, 9};

bool Check(int mid, int x) {
    // 실제로 해당하는 로직.
    return value[mid] <= x;
}

int binary_search(int lo, int hi, int x) {
    // lo를 F로 두자, hi를 T로  lowerBound -> X보다 작거나 같은값.
    int mid;
    while (lo + 1 < hi) {
        mid = (lo + hi) / 2;
        if (Check(mid, x))lo = mid;
        else hi = mid;
    }
    return lo;
}

int main() {
    // 7, 1,2,3,5,8,11 answer : 5
    cout << binary_search(0, 10, 7);
//    input();
//    solve();
}



long long sawing(int h) {
    long long ret = 0;
    for (int wood: woods) {
        if (wood > h)ret += (wood - h);
    }
    return ret;
}
void solve() {
    int left = 0;
    int right = 1e9;
    int mid = (left + right) / 2;

    while (left + 1 < right) {
        // value가 지금까지 나온것보다 적을 때만 정답을 갱신.
        mid = (left + right) / 2;

        if (sawing(mid) >= m) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left;
}

void input() {
    cin >> n >> m;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > MAX)MAX = num;
        woods.push_back(num);
    }

}



/**
4 7
20 15 10 17

5 20
4 42 40 26 46
*/
