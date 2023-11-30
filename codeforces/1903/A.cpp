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
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    bool sorted = true;
    rep(i, 0, n-1) if (A[i+1] < A[i]) { sorted = false; break; }

    if (!sorted && k == 1) cout << "NO\n";
    else cout << "YES\n";
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

