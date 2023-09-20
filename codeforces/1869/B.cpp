#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, a, b) for (auto i = (a); i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {

    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vll X(n+1), Y(n+1);
    rep(i, 1, n+1) cin >> X[i] >> Y[i];

    ll md_a = LONG_LONG_MAX/2, md_b = LONG_LONG_MAX/2;
    ll md = llabs(X[a] - X[b]) + llabs(Y[a] - Y[b]);
    rep(i, 1, k+1) {
        ll d_a = llabs(X[i] - X[a]) + llabs(Y[i] - Y[a]); 
        ll d_b = llabs(X[i] - X[b]) + llabs(Y[i] - Y[b]); 
        if (d_a < md_a) md_a = d_a;
        if (d_b < md_b) md_b = d_b;
    }

    if (md_a + md_b < md) cout << md_a + md_b << "\n";
    else cout << md << "\n";

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

