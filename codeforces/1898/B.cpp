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
    vector<ll> A(n);
    rep(i, 0, n) cin >> A[i];

    ll n_ops = 0;

    ll r_int = A[n-1];
    per(i, n-2, 0) {
        if (A[i] <= r_int) {
            r_int = A[i];
            continue;
        }

        ll k = (A[i] + r_int - 1) / r_int;
        if (A[i] % r_int != 0) r_int = A[i] / k;

        n_ops += k - 1;
    }

    cout << n_ops << endl;

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

