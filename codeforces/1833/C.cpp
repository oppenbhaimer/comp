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
    cin >> A[0];
    int parity = A[0] % 2;
    bool eqpar = true;
    rep(i, 1, n) {
        cin >> A[i];
        if (parity != (A[i]%2)) {
            eqpar = false;
        }
        parity = (A[i]%2);
    }
    if (eqpar) {
        cout << "YES" << endl;
        return;
    }

    int m = *min_element(A.begin(), A.end());
    if (m%2 != 1) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
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

