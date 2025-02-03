#include<iostream>
#include<vector>

using namespace std;

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int N;
vector<vector<int>> v;
int arr[21][21];
int number[401];


void input() {
    for (int i = 0; i < N * N; i++) {
        int num;
        for (int j = 0; j < 5; j++) {
            cin >> num;
            v[i].push_back(num);
        }
        number[v[i][0]]=i;
    }
}

pair<int, int> calCell(int x, int y, int cur) {
    int blank = 0;
    int favNum = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + xn[i];
        int yy = y + yn[i];
        if (xx < 0 || yy < 0 || xx >= N || yy >= N)continue;
        if (arr[yy][xx] == 0)blank++;
        for (auto j: v[cur]) {
            if (j == arr[yy][xx])favNum++;
        }
    }
    return {blank, favNum};
}

void sol() {
    for (int i = 0; i < N * N; i++) {
        int x = 0;
        int y = 0;
        int favNum = -1;
        int blank = -1;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (arr[j][k] != 0)continue;
                pair<int, int> cur = calCell(k, j, i);
                if (cur.second > favNum) {
                    favNum = cur.second;
                    x = k;
                    y = j;
                    blank = cur.first;
                } else if (cur.second == favNum) {
                    if (cur.first > blank) {
                        x = k;
                        y = j;
                        blank = cur.first;
                    }
                }
            }
        }
        arr[y][x] = v[i][0];
    }
}

int ans() {
    int ans=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
//            cout<<arr[i][j]<<" ";
            int fav = calCell(j, i, number[arr[i][j]]).second;
            switch (fav) {
                case 1:
                    ans+=1;
                    break;
                case 2:
                    ans+=10;
                    break;
                case 3:
                    ans+=100;
                    break;
                case 4:
                    ans+=1000;
                    break;
                default:
                    ans+=0;
                    break;
            }
        }
//        cout<<'\n';
    }
    return ans;
}

int main() {
    cin >> N;
    v.resize(N * N + 1);
    input();
    sol();


    cout<<ans();

}
