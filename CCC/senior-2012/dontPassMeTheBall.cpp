#include <bits/stdc++.h>
using namespace std;

int numScoring (int val) {
  int n = val - 1;

  return (n * (n-1) * (n-2)) / 6;
}

int main () {
  int J;

  cin >> J;

  cout << numScoring(J) << endl;

  return 0;
}
