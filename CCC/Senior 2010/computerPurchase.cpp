// Arnav Kumar
// Senior CCC 2010 Computer Purchase

#include <bits/stdc++.h>
// #include "../debug.h"
using namespace std;

// general macros
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

// bit macros
#define leastSig(n) (n & (-n))
#define mostSig(n) (1 << (fls(n) - 1)) // only for int
#define set(n, i) (n |= (1 << i))
#define test(n, i) (n & (1 << i))
#define reset(n, i) (n &= ~(1 << i))
#define flip(n, i) (n ^= (1 << i))


int N, R, S, D;
string name;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> computers;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> name >> R >> S >> D;
        computers.push(make_pair(-1 * (2*R + 3*S + D), name));
    }

    N = min(2, (int)computers.size());
    for (int i = 0; i < N; i++) {
        cout << computers.top().second << '\n';
        computers.pop();
    }

    return 0;
}