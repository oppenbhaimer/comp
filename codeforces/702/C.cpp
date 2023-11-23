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

    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, m) cin >> B[i];

    sort(B.begin(), B.end());
    int a = 0;
    rep(i, 0, n) {
        int r_idx = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        int r = -1;
        if (r_idx == m) r = B[m-1];
        else r = B[r_idx];
        int l_idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        int l = -1;
        if (B[l_idx] != A[i]) {
            if (l_idx == 0) l = B[0];
            else l = B[l_idx-1];
        }
        else l = B[l_idx];
        // cout << A[i] << " " << r << " " << l << endl;
        a = max(a, min(abs(A[i]-r), abs(A[i]-l)));
    }

    cout << a << endl;
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

