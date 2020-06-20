//UVa id 00514

#include <bits/stdc++.h>

using namespace std;

int main() {
    int qTrains, temp, i;
    stack<int> tYard;
    bool valid;

    while (scanf("%d", &qTrains), qTrains != 0) {
        while (scanf("%d", &temp), temp != 0) {
            while (!tYard.empty()) {tYard.pop();}
            i = 0;
            valid = true;
            
            for (int j = 0; j < qTrains; j++) {
                if (j) {scanf("%d", &temp);}

                while (tYard.empty() || temp != tYard.top()) {
                    if (i > qTrains) {valid = false; break;}
                    tYard.push(i);
                    i++;
                }

                tYard.pop();
            }

            if (valid) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}