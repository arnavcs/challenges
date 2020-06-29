//Arnav Kumar
//UVa id 11849

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

int numJack, numJill, tempID;
int counter;
queue<int> Jack;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> numJack >> numJill, numJack || numJill) {
        while (!Jack.empty()) {Jack.pop();}
        counter = 0;

        while (numJack--) {
            cin >> tempID;
            Jack.push(tempID);
        }

        while (numJill--) {
            cin >> tempID;

            if (Jack.empty()) {continue;}

            while (tempID > Jack.front()) {
                Jack.pop();
                if (Jack.empty()) {break;}
            } 
            
            if (tempID == Jack.front()) {
                counter++;
                Jack.pop();
            }
        }

        cout << counter << "\n";
    }

    return 0;
}