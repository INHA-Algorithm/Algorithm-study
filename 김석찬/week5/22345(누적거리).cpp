#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, Q, d[200011], k[200011];

vector <pair<long long, long long>> a;
vector <long long> v;
int main() {

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
        long long aa, xx;
		cin >> aa >> xx;
		a.push_back({ xx,aa });
		v.push_back(xx);
	}

	sort(a.begin(), a.end());
    sort(v.begin(),v.end());

	for (int i = 1; i <= N; i++) {
		d[i] = d[i - 1] + a[i - 1].first * a[i - 1].second;
		k[i] = k[i - 1] + a[i - 1].second;
	}

	while (Q--) {
        long long n;
		cin >> n;
        long long idx = lower_bound(v.begin(),v.end(), n) - v.begin();
		cout << d[N] - 2 * d[idx] - (n * (k[N] - 2 * k[idx])) << "\n";
	}
}