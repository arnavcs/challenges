//UVa id 00146

#include <bits/stdc++.h>

using namespace std;

int main() {
    string temp;
    
    while (cin >> temp, temp != "#") {
        if (next_permutation(temp.begin(), temp.end())) {
            cout << temp << endl;
        } else {
            printf("No Successor\n");
        }
    }

    return 0;
}