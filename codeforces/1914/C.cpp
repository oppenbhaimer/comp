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

    int n, k;
    cin >> n >> k;
    vi A(n), B(n);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];

    vi C(n+1);
    vi D(n+1);
    C[0] = B[0];
    rep(i, 1, n+1) C[i] = max(C[i-1], B[i]);
    D[0] = A[0];
    rep(i, 1, n+1) D[i] = D[i-1] + A[i];

    int ans = 0;
    rep(i, 0, n) {
        if (i+1 > k) break;
        ans = max(ans, D[i] + (k-1-i)*C[i]);
    }

    cout << ans << endl;

    /*
    int add = A[0];
    int ans = 0;
    int idx = 0;
    rep(i, 0, k) {
        ans += add;
        add = C[idx];
        if (idx < n-1 && A[idx+1] >= add) {
            add = A[idx+1];
            idx++;
        }
    }

    cout << ans << endl;
    */
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

