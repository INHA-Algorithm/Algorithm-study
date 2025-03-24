#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

/*
 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000)
 a==1 / b를 c로
 a==2 / b번째를 c로
 */

long long N, M, K;
vector<long long> arr;
vector<long long> Tree;

long long init(long long start, long long end, long long idx) {

    if (start == end) {
        return Tree[idx] = arr[start];
    }

    long long mid = (start + end) / 2;

    return Tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}

long long findTree(long long start, long long end, long long idx, long long findStart, long long findEnd) {
    if (start > findEnd || findStart > end) return 0;

    if (start >= findStart && end <= findEnd)return Tree[idx];

    long long mid = (start + end) / 2;
    return findTree(start, mid, idx * 2, findStart, findEnd) + findTree(mid + 1, end, idx * 2 + 1, findStart, findEnd);
}

void changeTree(long long start, long long end, long long idx, long long changeIdx, long long changeVal) {
    if (start > changeIdx || changeIdx > end)return;
    Tree[idx] = Tree[idx] + changeVal - arr[changeIdx];
    if (start != end) {
        long long mid = (start + end) / 2;
        changeTree(start, mid, idx * 2, changeIdx, changeVal);
        changeTree(mid + 1, end, idx * 2 + 1, changeIdx, changeVal);
    }
}

int main() {
    cin >> N >> M >> K;
    long long num;
    arr.push_back(0);
    for (long long i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }

    int h = (int) ceil(log2(N));
    Tree.resize(1 << (h + 1));

    init(1, N, 1);

    long long x, y;
    for (long long i = 0; i < M + K; i++) {
        cin >> num >> x >> y;
        if (num == 1) {
            changeTree(1, N, 1, x, y);
            arr[x]=y;
        } else {
            cout << findTree(1, N, 1, x, y) << '\n';
        }
    }
}

/*
 5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 3 7
2 2 5
 */