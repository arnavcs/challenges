// Arnav Kumar
// Huffman Encoding CCC 2010 senior

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


int N, tint;
char letters[1 << 10], tchar1, tchar2;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> tchar1;

    }

    return 0;
}