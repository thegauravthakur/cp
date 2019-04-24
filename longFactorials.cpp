#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define int long long

void multiply(int n, vector<int> &result) {
  vector<int> temp{};
  int carry = 0;
  for (long long i : result) {
    int x = (n * i) + carry;
    temp.push_back(x % 10);
    carry = x / 10;
  }
  while (carry > 0) {
    temp.push_back(carry % 10);
    carry = carry / 10;
  }

  result = temp;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> result{1};
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      multiply(i, result);
    }
    for (auto i = result.rbegin(); i != result.rend(); i++)
      cout << *i;

    cout << endl;
    result.clear();
  }
}
