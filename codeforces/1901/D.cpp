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
    rep(i, 0, n) cin >> A[i];

    vi P(n), S(n);
    P[0] = A[0];
    S[n-1] = A[n-1];
    rep(i, 1, n) P[i] = max(P[i-1]+1,A[i]);
    per(i, n-2, 0) S[i] = max(S[i+1]+1,A[i]);

    int ans = INT_MAX;
    rep(i, 0, n) {
        int cmp = A[i];
        if (i > 0) cmp = max(cmp, P[i-1]+(n-i));
        if (i < n-1) cmp = max(S[i+1]+(i+1), cmp);
        ans = min(ans, cmp);
    }

    cout << ans << endl;
        
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

