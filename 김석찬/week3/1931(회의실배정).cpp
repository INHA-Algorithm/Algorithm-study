#include<iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<int,int>m;
multimap<int,int>m1;
vector<pair<int,int>>v;

int main(){
    cin>>N;
    int a,b;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int cnt=0;
    int val=0;
    for(auto i:v){
        if(i.second>=val){
            val=i.first;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}