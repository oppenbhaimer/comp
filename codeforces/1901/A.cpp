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

    int n, x;
    cin >> n >> x;
    vi A(n+2);
    A[n+1] = x;
    rep(i, 1, n+1) cin >> A[i];
    // rep(i, 0, n+2) cout << A[i] << " "; cout << endl;
    vi B(n+1);
    rep(i, 0, n+1) B[i] = A[i+1] - A[i];
    int ans = *max_element(B.begin(), B.end());

    // rep(i, 0, n+1) cout << B[i] << " "; cout << endl;

    // cout << ans << " " << B[n] << endl;
    ans = max(ans, (B[n]*2));

    cout << ans << endl;
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

