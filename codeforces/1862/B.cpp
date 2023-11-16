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

    if (n == 1) {
        cout << 1 << endl << A[0] << endl;
        return;
    }

    vector<int> M;
    rep(i, 0, n-1) {
        if (A[i] > A[i+1]) {
            M.push_back(A[i]);
            M.push_back(A[i+1]);
        }
        else {
            M.push_back(A[i]);
        }
    }

    M.push_back(A[n-1]);

    cout << M.size() << endl;
    rep(i, 0, M.size()) cout << M[i] << " ";
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

