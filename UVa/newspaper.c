//UVa id 11340

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int moneyVals[256];
    int numTestCases, numLines, centVal, totVal;
    unsigned char c;

    scanf("%d", &numTestCases);
    while (numTestCases--) {
        memset(moneyVals, 0, sizeof(moneyVals));
        totVal = 0;

        scanf("%d", &numLines);

        while (numLines--) {
            scanf(" %c %d", &c, &centVal);

            moneyVals[(int)c] = centVal;
        }

        scanf("%d\n", &numLines);

        while (numLines--)  {
            while (scanf("%c", &c), c != '\n') {
                if (c != ' ') {
                    if ((int)c >= 0 && (int)c < 256) {
                        totVal += moneyVals[(int)c];
                    }
                }
            }
        }

        printf("%.2f$\n", (float)(totVal)/100);
    }

    return 0;
}