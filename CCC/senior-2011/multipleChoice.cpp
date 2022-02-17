#include <bits/stdc++.h>
using namespace std;

int N, counter;
char c;
vector<char> a;

int main () {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> c;
        a[i] = c;
    }

    counter = 0;

    for (int i = 0; i < N; i++) {
        cin >> c;
        if (c == a[i]) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
