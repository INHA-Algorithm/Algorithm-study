//
// Created by 김석찬 on 2025/03/24.
//

#include<iostream>

using namespace std;

/*
 원판을 아래와 같은 방법으로 총 T번 회전시키려고 한다. 원판의 회전 방법은 미리 정해져 있고, i번째 회전할때 사용하는 변수는 xi, di, ki이다.
번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
원판을 T번 회전시킨 후 원판에 적힌 수의 합을 구해보자.
 */

int N, M, T;

int arr[52][52];
int deleteArr[52][52];
int dn[] = {1, -1};

// x의 배수의 원판을
// d가 0 이면 시계방향
// K칸을 회전

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            deleteArr[i][j] = 0;
        }
    }
}

void sol(int x, int d, int k) {
    int copy[52][52];
    for (int i = x - 1; i < N; i += x) {
        for (int j = 0; j < M; j++) {
            int idx = (j + dn[d] * k + (M * 50)) % M;
            copy[i][idx] = arr[i][j];
        }
        for (int j = 0; j < M; j++) {
            arr[i][j] = copy[i][j];
        }
    }


    init();
    bool del = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int idx = (j + 1 + M) % M;
            if (arr[i][j] != 0 && arr[i][j] == arr[i][idx]) {
                del = true;
                deleteArr[i][j] = 1;
                deleteArr[i][idx] = 1;
            }
            if (arr[i][j] != 0 && i != N - 1 && arr[i][j] == arr[i+1][j]) {
                del = true;
                deleteArr[i][j] = 1;
                deleteArr[i+1][j] = 1;
            }
        }
    }
    int total = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (deleteArr[i][j] == 1) {
                arr[i][j] = 0;
            } else if(arr[i][j]!=0) {
                total += arr[i][j];
                cnt++;
            }
        }
    }
    if(cnt==0)return;
    if (!del) {
        int mod = total % cnt;
        total /= cnt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0)continue;
                if (mod == 0) {
                    if (arr[i][j] > total)arr[i][j]--;
                    else if (arr[i][j] < total)arr[i][j]++;
                } else {
                    if (arr[i][j] > total)arr[i][j]--;
                    else if (arr[i][j] <= total)arr[i][j]++;
                }
            }
        }
    }

}

int main() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int x, d, k;
    for (int i = 0; i < T; i++) {
        cin >> x >> d >> k;
        sol(x, d, k);
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            total += arr[i][j];
        }
    }
    cout << total;
}