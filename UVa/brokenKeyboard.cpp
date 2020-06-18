// UVa id 11988

#include <bits/stdc++.h>

using namespace std;

int main() {
    list<char>::iterator pos;
    char inChar[1000];
    list<char> beiju;

    while (cin.getline(inChar, 1000)) {
        beiju.resize(0);
        pos = beiju.begin();

        for (size_t i = 0; i < strlen(inChar); i++) {
            if (inChar[i] == ']') {
                pos = beiju.begin();
            } else if (inChar[i] == '[') {
                pos = beiju.end();
            } else {
                pos = beiju.insert(pos, inChar[i]);
            }
        }

        while (!beiju.empty()) {
            printf("%c", beiju.back());
            beiju.pop_back();
        }
        printf("\n");
    }

    return 0;
}