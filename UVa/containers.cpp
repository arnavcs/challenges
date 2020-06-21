//Uva id 1062

#include <bits/stdc++.h>

using namespace std;

int findIndex(vector<char> stacks, char container) {
    int min = 1;
    int max = stacks.size();
    int i;
    bool bigger;
    bool smaller; 

    while (i = (min + max) / 2, smaller = !(stacks[i-1] < container), bigger = (stacks[i] < container), !(smaller || bigger)) {
        if (smaller) {
            max = i;
        } if (bigger) {
            min = i;
        }
    }

    return i;
}

int main() {



    return 0;
}