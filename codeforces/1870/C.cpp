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

    int n, k;
    cin >> n >> k;
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    vector<vi> idxs(k+1,vi());
    vector<bool> exists(k+1, false);
    rep(i, 0, n) {
        idxs[A[i]].push_back(i);
        exists[A[i]] = true;
    }

    vi L_DP(k+1, 0);
    vi R_DP(k+1, 0);

    int t = k;
    while (!exists[t]) t--;
    L_DP[t] = idxs[t][0];
    R_DP[t] = idxs[t][idxs[t].size()-1];

    per(i, t-1, 1) {
        if (!exists[i]) {
            L_DP[i] = L_DP[i+1];
            R_DP[i] = R_DP[i+1];
        }
        else {
            L_DP[i] = min(L_DP[i+1], idxs[i][0]);
            R_DP[i] = max(R_DP[i+1], idxs[i][idxs[i].size()-1]);
        }
    }

    rep(i, 1, k+1) {
        if (!exists[i]) cout << "0 ";
        else cout << (R_DP[i] - L_DP[i] + 1)*2 << " ";
    }
    cout << "\n";

    // rep(i, 1, k+1) cout << L_DP[i] << " "; cout << "\n";
    // rep(i, 1, k+1) cout << R_DP[i] << " "; cout << "\n";

    // cout << "\n";


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

