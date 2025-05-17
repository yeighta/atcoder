# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int a, b;
    cin >> a >> b;

    string a_str = to_string(a);
    string b_str = to_string(b);

    string concat = a_str + b_str;
    int concat_int = stoi(concat);

    if (sqrt(concat_int) == floor(sqrt(concat_int))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}