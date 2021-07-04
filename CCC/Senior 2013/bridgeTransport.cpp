#include <bits/stdc++.h>
using namespace std;

int main () {
  int W, N, t, numCars = 0, sum = 0;
  queue<int> w;

  cin >> W >> N;

  while (N--) {
    cin >> t;
    w.push(t);
    sum += t;

    if (w.size() > 4) {
      sum -= w.front();
      w.pop();
    }

    if (sum > W) {
      cout << numCars << endl;
      return 0;
    }

    numCars++;
  }

  cout << numCars << endl;
  return 0;
} 
