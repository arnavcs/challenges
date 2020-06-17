//UVa id 11933

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int num, iter, a, b;
    bool isA;

    while (scanf("%d", &num), num) {
        iter = 0;
        a = 0;
        b = 0;
        isA = true;

        while (num) {
            if (num & (1 << iter)) {
                if (isA) {
                    a |= (1 << iter);
                } else {
                    b |= (1 << iter);
                }
                isA = !isA;

                num ^= (1 << iter);
            }

            iter++;
        }

        printf("%d %d\n", a, b);
    }

    return 0;
}