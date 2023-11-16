#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    rep(i, 0, n) cin >> S[i];

    bool got_v = false;
    bool got_i = false;
    bool got_k = false;
    bool got_a = false;

    rep(i, 0, m) {
        rep(j, 0, n) {
            if (S[j][i] == 'v' && !got_v) { got_v = true; break; }
            else if (S[j][i] == 'i' && got_v && !got_i) { got_i = true; break; }
            else if (S[j][i] == 'k' && got_v && got_i && !got_k) { got_k = true; break; }
            else if (S[j][i] == 'a' && got_v && got_i && got_k && !got_a) { got_a = true; break; }
        }
    }

    if (got_v && got_i && got_k && got_a) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

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

