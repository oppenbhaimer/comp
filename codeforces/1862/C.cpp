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

    vi A(n+1);
    // vi B(n+1, 0);
    rep(i, 1, n+1) {
        cin >> A[i];
    }

    rep(i, 1, n+1) {
        if (A[i] > n) {
            cout << "NO" << endl;
            return;
        }
        if (A[i] == i) {
            continue;
        }
        if (A[A[i]] < i) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

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

