//Arnav Kumar
//Problem Name 

#include <bits/stdc++.h>
using namespace std;

// general macros
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

// bit macros
#define leastSig(n) (n & (-n))
#define set(n, i) (n |= (1 << i))
#define test(n, i) (n & (1 << i))
#define reset(n, i) (n &= ~(1 << i))
#define flip(n, i) (n ^= (1 << i))


int T, K, q;
char temp, result[5];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> K;
        vector<vector<int>> o1(5), o2(5), same(5);
        memset(result, 0, sizeof(result));

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> temp;
                o1[j].push_back(temp - 'A');
            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> temp;
                o2[j].push_back(temp - 'A');
            }
        }

        for (int i = 0; i < 5; i++) {
            sort(o1[i].begin(), o1[i].end());
            sort(o2[i].begin(), o2[i].end());
            while (!(o1[i].empty() || o2[i].empty())) {
                if (o1[i][0] < o2[i][0]) {
                    o1[i].erase(o1[i].begin());
                } else if (o1[i][0] == o2[i][0]) {
                    q = o1[i][0];
                    same[i].push_back(o1[i][0]);
                    while (o1[i][0] == q && !o1[i].empty()) {
                        o1[i].erase(o1[i].begin());
                    }
                    while (o2[i][0] == q && !o2[i].empty()) {
                        o2[i].erase(o2[i].begin());
                    }
                } else {
                    o2[i].erase(o2[i].begin());
                }
            }
        }

        K--;
        for (int i = 0; i < 5; i++) {
            q = 1;
            for (int j = i+1; j < 5; j++) {
                q *= same[j].size();
            }
            if (!same[i].empty()) {
                result[i] = same[i][0] + 'A';
                same[i].erase(same[i].begin());
            } else {break; }
            while (K - q >= 0 && same[i].size()) {
                result[i] = same[i][0] + 'A';
                same[i].erase(same[i].begin());
                K -= q;
            }
        }

        if (K || !result[4]) {
            cout << "NO" << '\n';
        } else {
            cout << result << '\n';
        }
    }

    return 0;
}