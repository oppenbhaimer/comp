#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, k;
    cin >> n >> k;
    vi A(n+1);
    rep (i, 1, n+1) cin >> A[i];

    vi DP(n+1);
    DP[0] = MOD;
    DP[1] = 0;
    rep (i, 2, n+1) {
        int min_score = MOD;
        for (int j=1; i-j >= 1 && j <= k; j++) {
            if (DP[i-j] + abs(A[i-j]-A[i]) < min_score) {
                min_score = DP[i-j] + abs(A[i-j]-A[i]);
            }
        }
        DP[i] = min_score;
    }

    cout << DP[n] << endl;

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

