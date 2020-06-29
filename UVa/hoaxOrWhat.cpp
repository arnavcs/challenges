//Arnav Kumar
//UVa id 11136

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i <= b; ++i)

int days, customers, billVal;
unsigned long spent;
multiset<int> bills;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> days, days) {
        bills.clear();
        spent = 0;

        while (days--) {
            cin >> customers;

            while (customers--) {
                cin >> billVal;
                bills.insert(billVal);
            }

            spent += (*--bills.end() - *bills.begin());
            bills.erase(--bills.end());
            bills.erase(bills.begin());
        }

        cout << spent << "\n";
    }

    return 0;
}