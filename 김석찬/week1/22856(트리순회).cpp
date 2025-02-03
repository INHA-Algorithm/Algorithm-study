#include<iostream>
#include<vector>

using namespace std;

int N;
int ans;
int node_cnt;
bool visit[100001];
vector<vector<int>>v;

//중위순회하는 형식으로

void sol(int num,int height){
    if(num==-1){
        ans--;
        return;
    }
    for(int i=0; i<v[num].size(); i++){
        ans++;
        sol(v[num][i],height+1);
        if(!visit[num]){
            visit[num]=true;
            node_cnt++;
            ans++;
        }
        if(node_cnt==N){
            ans--;
            return;}
    }
}

int main(){
    cin>>N;
    v.resize(N+1);
    int a,b,c;
    for(int i=0; i<N; i++){
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[a].push_back(c);
    }
    sol(1,0);
    cout<<ans<<'\n';
}


/*
 *
 * 현재 위치한 노드의 왼쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 왼쪽 자식 노드로 이동한다.
그렇지 않고 현재 위치한 노드의 오른쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 오른쪽 자식 노드로 이동한다.
그렇지 않고 현재 노드가 유사 중위 순회의 끝이라면, 유사 중위 순회를 종료한다.
그렇지 않고 부모 노드가 존재한다면, 부모 노드로 이동한다.
 */

//중위 순회의 마지막은 왼 루 오

//        1
//     2      4
//  3       5    6
//                 7
//               8
//                 9