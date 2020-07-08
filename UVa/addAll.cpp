//Arnav Kumar
//UVa id 10954

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
#define fall(i, a, b) for (int i = a; i < b + 1; ++i)

int N, temp, ret;

priority_queue<int, vector<int>, greater<int>> nums;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N, N) {
        ret = 0;
        while (!nums.empty()) {nums.pop();}

        fall (i, 1, N) {
            cin >> temp;
            nums.push(temp);
        }

        while (nums.size()  > 1) {
            temp = nums.top();
            nums.pop();
            temp += nums.top();
            nums.pop();

            ret += temp;
            nums.push(temp);
        }

        cout << ret << '\n';
    }

    return 0;
}