//UVa id 10901

#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, n, t, m, arrivalTime, currentTime;
    char side[5];
    bool isLeft;
    queue<int> left, right;

    scanf("%d", &c);

    while (c--) {
        scanf("%d %d %d", &n, &t, &m);
        isLeft = true;
        currentTime = 0;
        int times[m];
        memset(times, 0, sizeof times);

        for (int q = 0; q < m; q++) {
            scanf("%d %s", &arrivalTime, side);
            while (currentTime < arrivalTime) {
                if (isLeft && (!(left.empty() && right.empty()))) {
                    for (int i = 0; i < n; i++) {
                        if (left.empty()) {break;}
                        times[left.front()] = currentTime + t;
                        left.pop();
                    }
                    currentTime += t;
                    isLeft = false;
                } else if (!isLeft && (!(left.empty() && right.empty()))) {
                    for (int i = 0; i < n; i++) {
                        if (right.empty()) {break;}
                        times[right.front()] = currentTime + t;
                        right.pop();
                    }
                    currentTime += t;
                    isLeft = true;
                } else {
                    currentTime = arrivalTime;
                }
            }

            if (side[0] == 'l') {
                left.push(q);
            } else {
                right.push(q);
            }
        }

        while (!(left.empty() && right.empty())) {
            if (isLeft) {
                for (int i = 0; i < n; i++) {
                    if (left.empty()) {break;}
                    times[left.front()] = currentTime + t;
                    left.pop();
                }
                currentTime += t;
            } else {
                for (int i = 0; i < n; i++) {
                    if (right.empty()) {break;}
                    times[right.front()] = currentTime + t;
                    right.pop();
                }
                currentTime += t;
            }

            isLeft = !isLeft;
        }

        for (int i = 0; i < m; i++) {
            printf("%d\n", times[i]);
        }
        printf("\n");
    }

    return 0;
}