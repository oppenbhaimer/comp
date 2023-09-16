#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n;
    vi A(n+1, 0);
    rep(i, 1, n+1) cin >> A[i];
    string s;
    cin >> s;
    s = "X" + s;
    vi DP(n+1);
    DP[0] = 0;
    rep(i, 1, n+1) DP[i] = DP[i-1] ^ A[i];

    int x = 0;
    rep(i, 1, n+1) if (s[i] == '1') x ^= A[i];

    int q, op;
    cin >> q;
    while(q-- > 0) {

        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            x ^= (DP[l-1] ^ DP[r]);
        }
        else {
            int g;
            cin >> g;
            if (g == 0) cout << (x ^ DP[n]) << " ";
            else cout << x << " ";
        }
    }
    cout << "\n";
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

