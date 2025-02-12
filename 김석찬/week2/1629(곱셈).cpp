//
// Created by 김석찬 on 2025/02/03.
//

#include <iostream>

using namespace std;

long long A, B, C;
long long func[32];

long long sol(long long a, long long b, long long c){
    if(b == 0) return 1;
    long long temp = sol(a, b / 2, c);
    if (b % 2 == 0)return (temp * temp) % c;
    else return (((temp * temp) % c) * a) % c;
}

int main() {
    cin >> A >> B >> C;

    cout<< sol(A,B,C);

}




