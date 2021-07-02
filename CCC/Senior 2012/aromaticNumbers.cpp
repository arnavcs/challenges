#include <bits/stdc++.h>
using namespace std;

map<char, int> r { {'I', 1}, 
                   {'V', 5}, 
                   {'X', 10}, 
                   {'L', 50}, 
                   {'C', 100}, 
                   {'D', 500}, 
                   {'M', 1000} };

int eval (string s) {
  int ret = 0;

  ret = (int) s[0] - '0';
  ret *= r[s[1]];

  if (s.size() > 2) {
    if (r[s[1]] < r[s[3]]) {
      ret *= -1;
    }

    return ret + eval(s.substr(2));
  }

  return ret;
}

int main () {
  string s;

  cin >> s;
  
  cout << eval(s) << endl;

  return 0;
}
