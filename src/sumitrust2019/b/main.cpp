# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int int_N;
    cin >> int_N;
    double N = int_N;
    
    double tax = 1.08;
    double X = ceil(N / tax);
    
    // 検算して一致すればOK
    if (floor(X * tax) == N) {
        cout << X << endl;
    } else {
        cout << ":(" << endl;
    }
}
