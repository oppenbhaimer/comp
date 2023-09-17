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
    vector<ll> A(n);
    rep(i, 0, n) cin >> A[i];

    ll prod = 1;
    rep(i, 0, n) {
        prod *= A[i];
        if (prod > 2*n) {
            int l = 1, r = n;
            while (A[l-1] == 1 && l <= r) l++;
            while (A[r-1] == 1 && r >= l) r--;
            cout << l << " " << r << "\n";
            return;
        }
    }

    vi non_1_idxs;
    rep(i, 0, n) if (A[i] != 1) non_1_idxs.push_back(i);

    vector<ll> prefix_sum(n+1); prefix_sum[0] = 0;
    vector<ll> prefix_prod(n+1); prefix_prod[0] = 1;

    rep(i, 0, n) {
        prefix_sum[i+1] = prefix_sum[i] + A[i];
        prefix_prod[i+1] = prefix_prod[i] * A[i];
    }

    // rep(i, 0, n+1) cout << prefix_sum[i] << " "; cout << "\n";
    // rep(i, 0, n+1) cout << prefix_prod[i] << " "; cout << "\n";

    ll max_ps = 0;
    ll mps_l = 1, mps_r = 1;
    rep(i, 0, non_1_idxs.size()) {
        rep(j, i, non_1_idxs.size()) {
            int li = non_1_idxs[i]+1;
            int lj = non_1_idxs[j]+1;
            ll qty = prefix_sum[li-1] + (prefix_prod[lj]/prefix_prod[li-1]) + (prefix_sum[n] - prefix_sum[lj]);
            if (qty > max_ps) {
                max_ps = qty;
                mps_l = li;
                mps_r = lj;
            }
        }
    }

    cout << mps_l << " " << mps_r << "\n";


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

