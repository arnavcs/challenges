//Uva id 10855

#include <bits/stdc++.h>

using namespace std;

void rotateArray(vector<vector<char>>& nList) {
    vector<vector<char>> temp = nList;

    for (int i = 0; i < nList.size(); i++) {
        for (int j = 0; j < nList.size(); j++) {
            nList[j][nList.size() - 1 - i] = temp[i][j];
        }
    }
}

void count(vector<vector<char>> nList, vector<vector<char>> NList) {
    int count = 0;
    bool isSame = true;

    for (int i = 0; i < NList.size() - nList.size() + 1; i++) {
        for (int j = 0; j < NList.size() - nList.size() + 1; j++) {
            isSame = true;

            for (int k = 0; k < nList.size(); k++) {
                for (int l = 0; l < nList.size(); l++) {
                    isSame &= (nList[k][l] == NList[i+k][j+l]);
                }
            }

            if (isSame) {
                count++;
            }
        }
    }

    printf("%d", count);
}

int main() {
    int N, n;

    while (scanf("%d %d", &N, &n), n || N) {
        if (n == 0) {
            printf("0 0 0 0\n");
        } else {
            vector<vector<char>> NList(N, vector<char>(N));
            vector<vector<char>> nList(n, vector<char>(n));

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    scanf(" %c", &NList[i][j]);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf(" %c", &nList[i][j]);
                }
            }

            for(int i = 0; i < 4; i++) {
                if (i) {printf(" ");}
                count(nList, NList);
                rotateArray(nList);
                // printArray(nList);
            }

            printf("\n");
        }
    }

    return 0;
}