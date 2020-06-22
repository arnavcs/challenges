//Uva id 1062

#include <bits/stdc++.h>

using namespace std;

int findIndex(vector<char> stacks, char container) {
    if (stacks[0] >= container) {
        return 0;
    }

    int min = 1;
    int max = stacks.size();
    int i;
    bool bigger;
    bool smaller; 

    while (i = (min + max) / 2, smaller = (stacks[i-1] >= container), bigger = (stacks[i] < container), (smaller || bigger)) {
        if (smaller) {
            max = i;
        } if (bigger) {
            min = i;
        }
    }

    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<char> stackTops;
    int caseNum = 0;

    while (getline(cin, line), line != "end") {
        stackTops.clear();
        stackTops.resize(0);

        while (!line.empty()) {
            if (stackTops.empty() || stackTops[stackTops.size() - 1] < line.front()) {
                stackTops.push_back(line.front());
            } else {
                stackTops[findIndex(stackTops, line.front())] = line.front();
            }
            line.erase(0, 1);
        }

        caseNum++;

        cout << "Case " << caseNum << ": " << stackTops.size() << endl; 
    }

    return 0;
}