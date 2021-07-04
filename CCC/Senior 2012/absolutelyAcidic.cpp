#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;

  map<int, int> m;
  int lnum = 0, slnum = 0;
  int R;

  while (N--) {
    cin >> R;

    if (m.count(R)) {
      m[R]++;
    } else {
      m[R] = 1;
    }
  }

  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second > lnum) {
      slnum = lnum;
      lnum = it->second;
    } else if (it->second > slnum && it->second < lnum) {
      slnum = it->second;
    }
  }

  pair<int, int> largest = {INT_MAX, -1}, secondlargest = {INT_MAX, -1};

  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second == lnum) {
      if (largest.first > it->first) {
        largest.first = it->first;
      }
      if (largest.second < it->first) {
        largest.second = it->first;
      }
    } else if (it->second == slnum) {
      if (secondlargest.first > it->first) {
        secondlargest.first = it->first;
      }
      if (secondlargest.second < it->first) {
        secondlargest.second = it->first;
      }
    }
  }

  if (largest.first != largest.second) {
    cout << largest.second - largest.first << endl;
  } else {
    cout << max(largest.second - secondlargest.first, secondlargest.second - largest.first) << endl;
  }

  return 0;
}

