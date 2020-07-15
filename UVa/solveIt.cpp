//Arnav Kumar
//Problem Name 

#include <bits/stdc++.h>
// #include "../debug.h"
using namespace std;

// general macros
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)
#define EPS 1e-7

// bit macros
#define leastSig(n) (n & (-n))
#define set(n, i) (n |= (1 << i))
#define test(n, i) (n & (1 << i))
#define reset(n, i) (n &= ~(1 << i))
#define flip(n, i) (n ^= (1 << i))


int p, q, r, s, t, u;

double f (double x) {
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

double fd (double x) {
    return (-1*p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x);
}

double newton() {
    if (f(0) == 0) {
        return 0;
    }
    double x = 0.5, xOld = 0;
    while (fabs(x - xOld) > EPS) {
        xOld = x;
        x = xOld - (f(xOld)/fd(xOld));
    }
    return x;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0) * f(1) > 0) {
            cout << "No solution" << '\n';
        } else {
            cout << fixed << setprecision(4) << newton() << '\n';
        }
    }

    return 0;
}