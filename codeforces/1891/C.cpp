
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
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    sort(A.begin(), A.end());

    ll a = 0;
    ll x = 0;
    int r = n-1;
    int l = 0;
    while (l < r) {
        if (x+A[l] < A[r]) {
            a += A[l];
            x += A[l];
            A[l] = 0;
            l++;
        }
        else {
            A[l] -= (A[r]-x);
            a += (A[r]-x) + 1;
            x = 0;
            A[r] = 0;
            r--;
        }
    }

    // cout << a << " " << x << " " << A[l] << endl;
    if (A[l] == 0) cout << a << endl;
    else if (A[l] == 1) cout << a + 1 << endl;
    else cout << a + ((A[l]+x+1)/2)-x + 1 << endl;
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

