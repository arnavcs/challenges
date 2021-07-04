#include <bits/stdc++.h>
using namespace std;

bool isDistinct (int year) {
  int bmap = 0, rem = 0;

  while (year) {
    rem = year % 10;
    year = year / 10;

    if (bmap & (1 << rem)) {
      return false;
    }
    bmap |= (1 << rem);
  }

  return true;
}

int nextDistinct (int year) {
  year++;

  while (!isDistinct(year)) {
    year++;
  }

  return year;
}

int main () {
  int Y;

  cin >> Y;
  cout << nextDistinct(Y) << endl;

  return 0;
}
