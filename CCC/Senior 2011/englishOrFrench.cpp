#include <bits/stdc++.h>
using namespace std;

int n, t, s;
char c;

int main () {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    t = s = 0;

    while (cin >> c) {
        if (c == 't' || c == 'T') {
            t++;
        } if (c == 's' || c == 'S') {
            s++;
        }
    }

    if (t > s) {
        cout << "English" << endl;
    } else {
        cout << "French" << endl;
    }

    return 0;
}
