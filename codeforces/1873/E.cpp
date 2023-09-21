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

    ll n, x;
    cin >> n >> x;

    vector<ll> A(n+1);
    rep(i, 1, n+1) cin >> A[i];
    A[0] = 0;

    sort(A.begin(), A.end());

    vector<ll> PS(n+1);
    PS[0] = 0;
    rep(i, 1, n+1) PS[i] = PS[i-1] + A[i];

    // rep(i, 0, n+1) cout << PS[i] << " "; cout << "\n";

    ll i = n;
    // cout << "W = " << A[i] << "*" << i << " - " << PS[i] << "\n";
    ll W = A[i]*i - PS[i];
    while (i >= 1 && W > x) {
        i -= 1;
        W = A[i] * i - PS[i];
    }

    // cout << A[i] << " + " << "(" << x << "-" << W << ")/" << i << "\n";
    cout << A[i] +  (x-W)/i << "\n";

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

