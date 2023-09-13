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
    vi A(n+1), B(n+1), C(n+1);

    rep(i, 1, n+1) cin >> A[i] >> B[i] >> C[i];

    vi DP_A(n+1), DP_B(n+1), DP_C(n+1);
    DP_A[0] = 0;
    DP_B[0] = 0;
    DP_C[0] = 0;

    rep(i, 1, n+1) {
        DP_A[i] = max(DP_B[i-1], DP_C[i-1]) + A[i];
        DP_B[i] = max(DP_A[i-1], DP_C[i-1]) + B[i];
        DP_C[i] = max(DP_B[i-1], DP_A[i-1]) + C[i];
    }

    if (DP_A[n] > DP_B[n]) cout << max(DP_A[n], DP_C[n]) << endl;
    else cout << max(DP_B[n], DP_C[n]) << endl;
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

