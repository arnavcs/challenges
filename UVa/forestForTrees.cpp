//Arnav Kumar
//Problem Name 

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

class UnionFindInt {
private:
    vector<int> p, rank;
public:
    UnionFindInt(int N) { 
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }
    void reset() {
        for (int i = 0; i < rank.size(); i++) {
            rank[i] = 0;
            p[i] = i;
        }
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else { 
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
    int numSets() {
        int r = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == i) {
                ++r;
            }
        }
        return r;
    }
    bool isHead(int i) {
        return p[i] == i;
    }
};

int numCases, pos;
set<int> trees, acorns;
UnionFindInt forest(26);
char temp, v1, v2, discard[100], letters[70];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numCases;

    while (numCases--) {
        forest.reset();
        trees.clear();
        acorns.clear();
        memset(letters, 0, sizeof(letters));

        while (cin >> temp, temp == '(') {
            
            cin >> v1 >> temp >> v2 >> temp;

            forest.unionSet(v1 - 'A', v2 - 'A');
        }

        cin >> discard;

        cin >> letters;

        for (int i = 0; i < 70; i++) {
            pos = (int)letters[i] - (int)'A';
            if (pos < 26 && pos >= 0) {
                if (!forest.isHead(pos)) {
                    if (acorns.count(forest.findSet(pos))) {
                        acorns.erase(acorns.find(forest.findSet(pos)));
                        trees.insert(forest.findSet(pos));
                    } else if (!trees.count(forest.findSet(pos))) {
                        trees.insert(forest.findSet(pos));
                    } 
                } else {
                    if (!trees.count(pos)) {
                        acorns.insert(pos);
                    }
                }
            }
        }

        cout << "There are " << trees.size() << " tree(s) and " << acorns.size() << " acorn(s).\n";
    }

    return 0;
}