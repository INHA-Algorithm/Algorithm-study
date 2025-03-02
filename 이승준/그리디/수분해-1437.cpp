#include <iostream>
#include <vector>


using namespace std;
#define fastio()  cin.tie(0);    ios::sync_with_stdio(0);
#define MAX 1000001
#define DEST 10007

/**
 * 접근법
 * 1. 절반씩 재귀적으로 나누면서 3이하일때까지 나눔. -> 오답 이유: 최적의 곱을 얻으려면 2보단 3이 많아야함.  3으로 최대한 나눠야 함.
 * 2. 3으로 최대한 나누고 나머지값에 따라 2의 개수를 처리. 3으로 나누고 나머지가 1이면 4라는 값으로 바꾸고 2*2로 변환. 3보단 2*2가 크기때문
 *
 * 어려웠던점
 * 오버플로우때문에 pow연산을 하고 DEST로 나눠주니 정답이 안나놨음.
 *  long long result = 1;
    result = (result * (long long) pow(3, three) % DEST) % DEST;
    result = (result * (long long) pow(2, two) % DEST) % DEST;
    cout<<result;
    return;
 */
vector<int> v;
long long n;

void input();

void solve();

int main() {
    fastio();
    input();
    solve();
}

void input() {
    // 재귀적으로 mid,mid+1을 구해나가는데, 3이하일때까지 쪼갬.
    cin >> n;
}

void solve() {
    if (n <= 3) {
        cout << n;
        return;
    }
    int three = n / 3;
    n %= 3;
    int two = 0;
    if (n == 1) {
        // 남은게 4
        three--;
        two += 2;
    } else if (n == 2)two++;

    long long result = 1;


    for (int i = 0; i < three; i++) {
        result *= 3;
        result %= DEST;
    }
    for (int i = 0; i < two; i++) {
        result *= 2;
        result %= DEST;
    }
    cout << result % DEST;
}