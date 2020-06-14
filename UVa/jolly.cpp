#include <iostream>
#include <cstdlib>
#include <vector>
#include <bitset>

using namespace std;

bool isJolly(bitset<3000>& bset, int prev, int curr) {
    int difference = curr - prev;
    difference = difference > 0 ? difference : difference * -1;

    if (bset.test(difference - 1)) {
        return false;
    } 
    bset.set(difference - 1);

    return true;
}

int main() {
    int inputSize, prev, curr;
    bool isValid, first;
    bitset<3000> bset;

    while (scanf("%d", &inputSize) != EOF) {
        isValid = true;
        first = true;
        bset.reset();
        while (inputSize--) {
            prev = curr;
            scanf("%d", &curr);
            if (first) {
                first = false;
            } else {
                if (!isJolly(bset, prev, curr)) {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not Jolly" << endl;
        }
    }
}