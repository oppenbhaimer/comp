
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {

    int n;
    cin >> n;

    vector<vector<uint8_t>> M(n,vector<uint8_t>(n));

    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, n) M[i][j] = (s[j] - '0');
    }

    vector<vll> DP(n,vll(n, 0));
    vector<vector<uint8_t>> flip(n,vector<uint8_t>(n, 0));
    ll tot_flips = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            // compute num_flips in range of this cell
            ll n_flips = 0;
            if (i == 0) n_flips = 0;
            else if (i == 1) {
                if (j > 0) n_flips += flip[i-1][j-1];
                n_flips += flip[i-1][j];
                if (j < n-1) n_flips += flip[i-1][j+1];
            }
            else {
                if (j == 0) {
                    n_flips += DP[i-1][j+1];
                }
                else if (j == n-1) {
                    n_flips += DP[i-1][j-1];
                }
                else {
                    n_flips = (DP[i-1][j-1] + DP[i-1][j+1] - DP[i-2][j]);
                }
                n_flips += flip[i-1][j];
            }
            if (n_flips % 2 != M[i][j]) {
                n_flips += 1;
                flip[i][j] = 1;
                tot_flips += 1;
            }
            DP[i][j] = n_flips;
        }
    }

    // rep(i, 0, n) {
    //     rep(j, 0, n) {
    //         cout << (int)flip[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // rep(i, 0, n) {
    //     rep(j, 0, n) {
    //         cout << (int)DP[i][j];
    //     }
    //     cout << '\n';
    // }
    cout << tot_flips << "\n";

}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
