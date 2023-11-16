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

    vi A(n), B(n);
    vi I(n);
    iota(I.begin(), I.end(), 0);

    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];

    sort(B.begin(), B.end());
    //sort(A.begin(), A.end());
    sort(I.begin(), I.end(), [&A](int i1, int i2) { return A[i1] < A[i2]; });
    // sort(A.begin(), A.end());
    vi J(n);
    rep(i, 0, n) J[I[i]] = i;

    rep(i, 0, n) cout << B[J[i]] << " ";
    cout << endl;
    
    
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

