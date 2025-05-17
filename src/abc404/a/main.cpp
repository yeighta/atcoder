# include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    string S;
    cin >> S;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < alphabet.size(); i++) {
        if (S.find(alphabet[i]) == string::npos) {
            cout << alphabet[i] << endl;
            return 0;
        }
    }
}
