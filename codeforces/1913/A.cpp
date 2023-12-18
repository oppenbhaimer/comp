#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, a, b) for (auto i = (a); i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

  string s;
  cin >> s;

  per(i, s.size() - 1, 1) {
    if (s[i] == '0')
      continue;
    int b = std::stoi(s.substr(i));
    int a = std::stoi(s.substr(0, i));
    if (b > a) {
      cout << a << " " << b << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(int argc, char **argv) {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
