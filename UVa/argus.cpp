//Arnav Kumar
//UVa id 01203

#include <bits/stdc++.h>
using namespace std;

using t = pair<pair<int, int>, int>;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

priority_queue<t, vector<t>, greater<t>> m;
t tp;
int t1, t2, gens;
char word[10];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> word, word[0] != '#') {
        cin >> t1 >> t2;

        m.push(make_pair(make_pair(t2, t1), t2));
    }
    
    cin >> gens;

    while (gens--) {
        tp = m.top();
        cout << tp.first.second << "\n";

        m.pop();

        tp.first.first += tp.second;
        m.push(tp);
    }

    return 0;
}