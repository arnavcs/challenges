//Arnav Kumar
//UVa id 11286

#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int students, courseNum, largest, sum;
    unordered_map<bitset<500>, int> m;
    unordered_map<bitset<500>, int>::iterator it;
    bitset<500> tempBitset;

    while(scanf("%d", &students), students) {
        m.clear();

        while (students--) {
            tempBitset.reset();
            for (int i = 0; i < 5; ++i) {
                scanf("%d", &courseNum);
                tempBitset.set(courseNum);
            }

            m[tempBitset]++;
        }

        largest = 0;
        sum = 0;
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second > largest) {
                sum = it->second;
                largest = it->second;
            } else if (it->second == largest) {
                sum += it->second;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}