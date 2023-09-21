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
    ll k;
    cin >> n >> k;
    vector<ll> A(n), H(n);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> H[i];

    if (n == 1) {
        if (A[0] > k) cout << "0\n";
        else cout << "1\n";
        return;
    }

    vector<vector<ll>> div_sub;
    int i=0;
    while (i < n) {
        div_sub.push_back(vector<ll>());
        while (i < n-1 && H[i] % H[i+1] == 0) {
            div_sub[div_sub.size()-1].push_back(A[i]);
            i++;
        }
        div_sub[div_sub.size()-1].push_back(A[i]);
        i++;
    }

    // for (auto v : div_sub) {
    //     for (auto i : v) cout << i << " ";
    //     cout << "\n";
    // }

    int mds_len = 0;
    for (auto v : div_sub) {
        ll sum = 0;
        int n = 0;
        int maxn = 0;
        for (int i=0; i<v.size(); i++) {
            if ((sum+v[i]) <= k) {
                sum += v[i];
                n++;
            }
            else if (sum != 0) {
                sum = sum - v[i-n] + v[i];
            }
            maxn = max(n, maxn);
        }

        if (maxn > mds_len) mds_len = maxn;
    }

    cout << mds_len << "\n";
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

