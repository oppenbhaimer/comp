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
    vi A(n+2);
    rep(i, 1, n+1) cin >> A[i];
    A[0] = 0;
    A[n+1] = 0;

    ll ans = 0;
    rep(i, 1, n+1) {
        int j = i-1;
        while (A[i] == A[i+1]) i++;
        if (A[i] <= A[j] && A[i] <= A[i+1]) {
            ans -= A[i] ;
            // cout << i << " minima" << endl;
        }
        else if (A[i] >= A[j] && A[i] >= A[i+1]) {
            ans += A[i];
            // cout << i << " maxima" << endl;
        }
    }

    cout << ans - 1 << endl;

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

