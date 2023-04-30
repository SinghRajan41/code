#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_tests;
    cin >> num_tests;

    for (int test = 0; test < num_tests; ++test) {

        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (n % 2 == 1) {
            cout << "Mike\n";
            continue;
        }

        int smallest = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] < a[smallest])
                smallest = i;

        if (smallest % 2 == 0) cout << "Joe\n";
        else cout << "Mike\n";
    }
}