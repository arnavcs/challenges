//Uva id 10107

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> integers;
    int temp;

    while (scanf("%d", &temp) != EOF) {
        integers.push_back(temp);
        nth_element(integers.begin(), integers.begin() + (integers.size() / 2), integers.end());
        if (integers.size() % 2) {
            printf("%d\n", integers[integers.size() / 2]);
        } else {
            nth_element(integers.begin(), integers.begin() + (integers.size() / 2) - 1, integers.end());
            printf("%d\n", (integers[integers.size() / 2] + integers[integers.size() / 2 - 1]) / 2);
        }
    }
}