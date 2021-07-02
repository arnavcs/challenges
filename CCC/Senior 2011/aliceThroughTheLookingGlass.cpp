#include <bits/stdc++.h>
using namespace std;

int T, m, mx, my;
vector<int> fives = {1, 5};

int getFive (int q) {
  while (fives.size() <= q) {
    fives.push_back(fives.back() * 5);
  }

  return fives[q];
}

int basicColour (int x, int y) {
  if ((x == 1 && y == 0) || (x == 2 && y == 0) || (x == 3 && y == 0) || (x == 2 && y == 1)) {
    return 3;
  } else if ((x == 0 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 1) || (x == 4 && y == 0)) {
    return 2;
  } else {
    return 1;
  }
}

bool isCrystal (int mag, int x, int y) {
  int nx, ny, q;
  for (int i = mag - 1; i >= 0; i--) {
    nx = x / getFive(i);
    ny = y / getFive(i);

    q = basicColour(nx, ny);

    if (q == 0) {
      return false;
    } else if (q == 3) {
      return true;
    } else {
      x = x % getFive(i);
      y = y % getFive(i);
    }
  }

  return false;
}

int main () {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> m >> mx >> my;

    if (mx < getFive(m - 1) || mx >= 4 * getFive(m - 1) || my >= 3 * getFive(m - 1)) {
      cout << "empty" << endl;
    } else {
      if (isCrystal(m, mx, my)) {
        cout << "crystal" << endl;    
      } else {
        cout << "empty" << endl;
      }
    }
  }

  return 0;
}
