#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    int b = 0, x = 0;
    rep(i, 0, n) {
        cin >> A[i];
        x ^= A[i];
    }
    rep(i, 0, m) {
        int t;
        cin >> t;
        b |= t;
    }

    if (n % 2 != 0) {
        int max = 0;
        rep(i, 0, n) max ^= (b | A[i]);
        cout << x << " " << max << "\n";
    }
    else {
        int min = 0;
        rep(i, 0, n) min ^= (b | A[i]);
        cout << min << " " << x << "\n";
    }

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

