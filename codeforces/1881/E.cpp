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
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    vector<int> DP(n,n+1);

    DP[n-1] = 1;
    for (int i=n-2; i>=0; i--) {
        if (i+A[i]+1 > n) DP[i] = min(DP[i+1]+1, n+1);
        else if (i+A[i]+1 == n) DP[i] = min(DP[i+1]+1, 0);
        else DP[i] = min(DP[i+1]+1, DP[i+A[i]+1]);
    }

    cout << DP[0] << endl;

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

