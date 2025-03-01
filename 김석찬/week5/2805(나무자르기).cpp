//
// Created by 김석찬 on 2025/02/23.
//

#include<iostream>
#include <algorithm>
using namespace std;

long long n, m, Max;
int tree[1000001];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tree[i];
    }

    sort(tree, tree + n);

    long long lowIdx = 0;
    long long highIdx = tree[n - 1];

    while(lowIdx <= highIdx){
        long long sum = 0;
        long long cut = (lowIdx + highIdx) / 2;

        for(int i = 0; i < n; i++) {
            if(tree[i] - cut > 0) {
                sum += tree[i] - cut;
            }
        }
        if(sum >= m){
            Max = cut;
            lowIdx = cut + 1;
        } else{
            highIdx = cut - 1;
        }
    }

    cout << Max;
}