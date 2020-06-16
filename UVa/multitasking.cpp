//UVa id 11926

#include <bits/stdc++.h>

using namespace std;

int main() {
    int norep, rep, start, end, repeat;
    bitset<1000000> times;
    bool isValid;

    while (scanf("%d %d", &norep, &rep), norep || rep) {
        times.reset();
        isValid = true;
        for (int i = 0; i < norep; i++) {
            scanf("%d %d", &start, &end);
            for (int j = start; j < end; j++) {
                if (times.test(j)) {
                    isValid = false;
                    break;
                }
                times.set(j);
            }
        }
        for (int i = 0; i < rep; i++) {
            scanf("%d %d %d", &start, &end, &repeat);
            
            while (start < 1000000) {
                for (int j = start; j < end; j++) {
                    if (j >= 1000000) {
                        break;
                    }
                    if (times.test(j)) {
                        isValid = false;
                        break;
                    }
                    times.set(j);
                }
                start += repeat;
                end += repeat;
            }
        }

        if (isValid) {
            printf("NO CONFLICT\n");
        } else {
            printf("CONFLICT\n");
        }
    }

    return 0;
}