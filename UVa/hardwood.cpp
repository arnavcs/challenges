//UVa id 10226

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string species;
    int numCases, totalTrees;
    map<string, int> trees;
    map<string, int>::iterator tempIter;

    cin >> numCases;
    cin.ignore();
    getline(cin, species);

    while (numCases--) {
        trees.clear();
        totalTrees = 0;

        while(getline(cin, species)) {
            if (species == "")
                break;
            trees[species]++;

            totalTrees++;
        }

        for (tempIter = trees.begin(); tempIter != trees.end(); tempIter++) {
            std::cout << tempIter->first << " " << fixed << setprecision(4) << tempIter->second*100.0/totalTrees << "\n";
        }

        cout << "\n";
    }
    

    return 0;
}