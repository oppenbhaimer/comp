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

    ll best_sum = LLONG_MIN;
    ll curr_sum = 0;
    rep(i, 0, n) {
        if (i > 0 && abs(A[i-1])%2 == abs(A[i])%2) {
            curr_sum = (ll)A[i];
        }
        else {
            curr_sum = max((ll)A[i], curr_sum+A[i]);
        }
        best_sum = max(best_sum, curr_sum);
    }

    cout << best_sum << endl;
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

