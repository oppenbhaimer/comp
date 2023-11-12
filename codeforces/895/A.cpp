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

    int n;
    cin >> n;

    vi A(n);
    ll S = 0;
    rep(i, 0, n) {
        cin >> A[i];
        S += A[i];
    }

    ll md = MOD;
    rep(i, 0, n) {
        rep(j, i, n) {
            ll s = 0;
            rep(k, i, j+1) {
                s += A[k];
            }
            ll diff = llabs(s - (S-s));
            if (diff < md) md = diff;
        }
    }

    cout << md << endl;

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