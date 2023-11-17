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
    vi A(n+1);
    rep(i, 1, n+1) cin >> A[i];

    vector<ll> P(n+1);
    P[0] = 0;
    rep(i, 1, n+1) P[i] = P[i-1] + A[i];

    ll diff = 0;

    rep(i, 1, n) {
        if (i*2 > n) break;
        if (n%i != 0) continue;
        ll m = LLONG_MAX, M = LLONG_MIN;
        for (int j=i; j<=n; j+=i) {
            ll d = P[j] - P[j-i];
            if (d < m) m = d;
            if (d > M) M = d;
        }

        if (M-m > diff) diff = M-m;

    }

    cout << diff << endl;

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

