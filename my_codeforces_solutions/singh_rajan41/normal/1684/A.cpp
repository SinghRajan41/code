#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        string n;
        cin >> n;
        if (n.size() == 2) {
            cout << n[1] << '\n';
        } else {
            cout << *min_element(n.begin(), n.end()) << '\n';
        }
    }
    return 0;
}