#include<iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll a, b, c;

ll divide_conquer(ll dist) {
    if (dist == 1)return a % c;
    ll ret = divide_conquer(dist / 2);
    if (dist % 2 == 0) {
        //짝수일때
        return ret * ret % c;
    } else {
        //홀수 일때
        return ((ret * ret % c) * (a % c)) % c;
    }
}

int main() {
    cin >> a >> b >> c;
    cout << divide_conquer(b);
}