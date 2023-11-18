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

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    if (s[0] != t[0]) {
        cout << "No\n"; return;
    }
    if (s[n-1] != t[m-1]) {
        cout << "No\n"; return;
    }

    if (m == 1) {
        rep(i, 0, n) {
            if (s[i] != t[0]) {
                cout << "No\n"; return;
            }
        }
    }

    rep(i, 1, n-1) {
        char c = s[i];
        bool valid = false;
        rep(j, 0, m) {
            if (t[j] == s[i]) {
                if (j == 0 && (s[i+1] == t[1] || s[i+1] == t[0])) { valid = true; break; }
                else if (j == m-1 && (s[i-1] == t[m-2] || s[i-1] == t[m-1])) { valid = true; break; }
                else if ((s[i-1] == t[j-1] || s[i-1] == t[m-1]) &&
                         (s[i+1] == t[j+1] || s[i+1] == t[0]  )) { valid = true; break; }
            }
        }
        if (!valid) {
            // cout << "No match for char " << c << " at position " << i << endl;
            cout << "No\n"; return;
        }
    }

    cout << "Yes\n";

}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

