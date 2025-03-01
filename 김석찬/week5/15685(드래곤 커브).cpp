#include <iostream>
#include<vector>
using namespace std;


// 규칙 방향으로 가고 거꾸로 나열한 다음 +1을 하면 나온다/
//0: x좌표가 증가하는 방향 (→)
//1: y좌표가 감소하는 방향 (↑)
//2: x좌표가 감소하는 방향 (←)
//3: y좌표가 증가하는 방향 (↓)

int N;
vector<vector<int>>v;
int arr[101][101];
int xn[4]={1,0,-1,0};
int yn[4]={0,-1,0,1};

void sol(int dis,int size){
    v[0].push_back(dis);
    for(int i=1; i<=size; i++){
        for(int j=0; j<v[i-1].size(); j++){
            v[i].push_back(v[i-1][j]);
        }
        for(int j=v[i-1].size()-1; j>=0; j--){
            int temp=v[i-1][j];
            if(temp==3)temp=-1;
            v[i].push_back(temp+1);
        }
    }
}

void dragon(int x,int y,int size){
    arr[y][x]=1;
    for(int i=0; i<v[size].size(); i++){
        x=x+xn[v[size][i]];
        y=y+yn[v[size][i]];
        if(x<0 || y<0 || x>100 || y>100)continue;
        arr[y][x]=1;
    }
}

bool chk_square(int x,int y){
    return (arr[y][x] && arr[y][x+1] && arr[y+1][x+1] && arr[y+1][x]);
}

int main(){
    int x,y,d,g;
    cin>>N;
    v.resize(11);

    for(int i=0; i<N; i++){
        cin>>x>>y>>d>>g;
        sol(d,g);
        dragon(x,y,g);
        for(int j=0; j<=g; j++)v[j].clear();
    }

    int ans=0;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(chk_square(j,i))ans++;
        }
    }
    cout<<ans;

}