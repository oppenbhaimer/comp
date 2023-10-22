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
    s = '1' + s;
    int idx[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    rep(i, 1, s.length()) {
        sum += abs(idx[s[i]-'0'] - idx[s[i-1]-'0']);
    }
    cout << sum + s.length() - 1 << '\n';

}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

