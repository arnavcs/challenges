//UVa id 10264

#include <bits/stdc++.h>

using namespace std;

int main() {
    int dim, size, maxSum, temp;
    vector<int> potencies;

    while (scanf("%d", &dim) != EOF) {
        size = 1 << dim;

        potencies.clear();
        potencies.resize(size);

        for (int i = 0; i < size; i++) {
            scanf("%d", &temp);
            for (int j = 0; j < dim; j++) {
                potencies[i ^ (1 << j)] += temp;
            }
        }

        maxSum = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < dim; j++) {
                temp = i ^ (1 << j);
                if (temp > i) {maxSum = max(potencies[temp] + potencies[i], maxSum);}
            }
        }

        printf("%d\n", maxSum);
    }

    return 0;
}