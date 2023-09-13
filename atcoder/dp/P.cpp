#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

vi DP(1e5+5, -1);

int recurse(vector<vi>& G, int i, int p);

int get_dp(vector<vi>& G, int i, int p) {
    if (DP[i] < 0) DP[i] = recurse(G, i, p);
    return DP[i];
}

int recurse(vector<vi>& G, int i, int p) {

    ll n_p = 1;
    ll nn_p = 1;
    for (int n_i : G[i]) {
        if (n_i != p) {
            n_p = (n_p * (ll)get_dp(G, n_i, i)) % MOD;
            for (int n_j : G[n_i]) {
                if (n_j != i) {
                    nn_p = (nn_p * (ll)get_dp(G, n_j, n_i)) % MOD;
                }
            }
        }
    }

    return (n_p + nn_p) % MOD;
}


void solve() {

    int n;
    cin >> n;
    vector<vi> G(n+1);

    rep(i,0,n-1) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = recurse(G, 1, 0);

    cout << ans << endl;

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

