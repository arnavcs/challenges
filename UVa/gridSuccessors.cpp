#include <bits/stdc++.h>

using namespace std;

int simGen(int gridVal) {
    int newVal = 0;
    for (int i = 0; i < 9; i++) {
        if ((i % 3) != 2 && (gridVal & (1 << (i + 1)))) {
            newVal ^= (1 << i);
        }
        if ((i % 3) && (gridVal & (1 << (i - 1)))) {
            newVal ^= (1 << i);
        }
        if ((i < 6) && (gridVal & (1 << (i + 3)))) {
            newVal ^= (1 << i);
        }
        if ((i > 2) && (gridVal & (1 << (i - 3)))) {
            newVal ^= (1 << i);
        }
    }

    return newVal;
}

int main() {
    vector<int> instances;
    bool isIn;
    int numCases, gridVal;
    char temp;

    scanf("%d", &numCases);

    while (numCases--) {
        fill(instances.begin(), instances.end(), 0);
        instances.resize(0);
        gridVal = 0;

        for (int i = 0; i < 9; i++) {
            scanf(" %c", &temp);
            if (temp == '1') {gridVal |= (1 << i);}
        }
        
        isIn = false;

        while (!isIn) {
            instances.push_back(gridVal);
            gridVal = simGen(gridVal);

            isIn = false;
            for (int i = 0; i < (int)instances.size(); i++) {
                if (instances[i] == gridVal) {
                    isIn = true;
                    printf("%d\n", i - 1);
                    break;
                }
            }
        }
    }
}