// Arnav Kumar
// UVa id 11292

#include <bits/stdc++.h>
#include "../debug.h"
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

priority_queue<int, vector<int>, greater<int>> knights, dragons;
int n, m, temp, pos, ret;
bool done;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m, n || m) {
        while (!knights.empty()) {knights.pop();}
        while (!dragons.empty()) {dragons.pop();}

        while (n--) {
            cin >> temp;
            dragons.push(temp);
        }

        while (m--) {
            cin >> temp;
            knights.push(temp);
        }

        cout << knights;

        ret = 0;
        done = false;

        while (!dragons.empty()) {
            if (knights.empty()) {
                cout << "Loowater is doomed!\n";
                done = true;
                break;
            }

            if (knights.top() >= dragons.top()) {
                ret += knights.top();
                knights.pop();
                dragons.pop();
            } else {
                knights.pop();
            }
        }

        if (!done) {
            cout << ret << '\n';
        }
    }

    return 0;
}