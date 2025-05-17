# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int R, X;
    cin >> R >> X;

    if (X == 1) {
        if (R >= 1600 && R <= 2999) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (R >= 1200 && R <= 2399) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
