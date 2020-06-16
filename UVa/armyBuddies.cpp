//UVa id 12356

#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;

int main() {
    int soldiers, numLosses, leftBound, rightBound;

    while (scanf("%d %d", &soldiers, &numLosses), soldiers || numLosses) {

        int right[soldiers];
        int left[soldiers];

        for (int i = 0; i < soldiers; i++) {
            if (i + 1 == soldiers) {
                right[i] = 0;
            } else {
                right[i] = i + 2;
            }

            if (!i) {
                left[i] = 0;
            } else {
                left[i] = i;
            }
        }

        for (int i = 0; i < numLosses; i++) {
            scanf("%d %d", &leftBound, &rightBound);
            
            if (left[leftBound - 1]) {
                printf("%d ", left[leftBound - 1]);
                right[left[leftBound - 1] - 1] = right[rightBound - 1];
            } else {
                printf("* ");
            }

            if (right[rightBound - 1]) {
                printf("%d\n", right[rightBound - 1]);
                left[right[rightBound - 1] - 1] = left[leftBound - 1];
            } else {
                printf("*\n");
            }
        }

        printf("-\n");
    }

    return 0;
}