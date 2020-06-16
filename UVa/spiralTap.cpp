//UVa id 10920

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int SZ;
    long long P, sqrtP;
    int coors[2];

    while (scanf("%d %lld", &SZ, &P), SZ || P) {
        coors[0] = coors[1] = (SZ + 1) / 2;


        sqrtP = sqrtl(P);
        if (sqrtP % 2) {
            coors[0] += (sqrtP - 1) / 2;
            coors[1] += (sqrtP - 1) / 2;

            P -= sqrtP * sqrtP;

            for (long long i = 0LL; i < P; i++) {
                if (i < 1) {
                    coors[1]++;
                } else if (i <= sqrtP) {
                    coors[0]--;
                } else {
                    coors[1]--;
                }
            }
        } else {
            coors[0] -= sqrtP / 2;
            coors[1] -= (sqrtP / 2) - 1;

            P -= sqrtP * sqrtP;

            for (long long i = 0LL; i < P; i++) {
                if (i < 1) {
                    coors[1]--;
                } else if (i <= sqrtP) {
                    coors[0]++;
                } else {
                    coors[1]++;
                }
            }
        }
        printf("Line = %d, column = %d.\n", coors[1], coors[0]);
    }

    return 0;
}