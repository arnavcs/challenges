//Arnav Kumar
//UVa id 11572

#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCases, numSnow, snowType, curr, longest;
    unordered_map<int, int> snowflakes;

    cin >> numCases;

    while (numCases--) {
        curr = 0;
        longest = 0;

        cin >> numSnow;

        for (int i = 1; i <= numSnow; ++i) {
            cin >> snowType;

            if (snowflakes[snowType] && i - snowflakes[snowType] <= curr) {
                longest = max(longest, curr);
                curr = i - snowflakes[snowType];
                snowflakes[snowType] = i;
            } else {
                curr++;
                snowflakes[snowType] = i;
            }
        }

        longest = max(longest, curr);

        cout << longest << endl;
        snowflakes.clear();
    }

    return 0;
}