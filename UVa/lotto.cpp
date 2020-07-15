//Arnav Kumar
//UVa id 00441

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

int k, temp;
bool t;
string line;
vector<int> S;
vector<bool> p;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    temp = false;

    while (cin >> k, k) {
        S.resize(0);
        p.resize(0);

        while (k--) {
            cin >> temp;
            S.push_back(temp);
        }

        for (int i = 0; i < 6; i++) {
            p.push_back(1);
        }

        for (int i = 0; i < S.size() - 6; i++) {
            p.push_back(0);
        }

        do {
            t = false;
            for (int i = 0; i < S.size(); i++) {
                if (p[i]) {
                    if (t) {cout << ' ' << S[i];}
                    else {cout << S[i]; t = true;}
                }
            }
            cout << '\n';
        } while(prev_permutation(p.begin(), p.end()));

        cout << '\n';
    }

    return 0;
}