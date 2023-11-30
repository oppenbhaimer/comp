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
    vector<vi> M(n, vi(n, 0));

    rep(i, 0, n) rep(j, 0, n) cin >> M[i][j];

    if (n == 1) {
        cout << "YES\n7\n"; return;
    }

    vector<vi> bits(n, vi(30, 2));

    /*
    vector<uint32_t> rors, cors;

    rep(i, 0, n) {
        int ror = 0;
        rep(j, i+1, n) {
            ror |= M[i][j];
        }
        rors.push_back(ror);
    }

    rep(i, 0, n-1) cout << rors[i] << " "; cout << endl;

    rep(j, 1, n) {
        int cor = 0;
        rep(i, 0, j) {
            cor |= M[i][j];
        }
        cors.push_back(cor);
    }

    rep(i, 0, n-1) cout << cors[i] << " "; cout << endl;

    vector<uint32_t> A;
    rep(i, 0, n-2) {
        A.push_back(rors[i+1] & ~rors[i]);
    }

    A.push_back(cors[n-1] & ~cors[n-2]);

    cout << "YES\n";
    rep(i, 0, n) cout << A[i] << " "; cout << endl;
    */

    rep(u, 0, 2) {
        rep(i, 0, n) {
            rep(j, i+1, n) {
                rep(k, 0, 30) {
                    if (M[i][j] & (1<<k)) {
                        if (bits[i][k] == 0 && bits[j][k] == 0) {
                            cout << "NO" << endl;
                            return;
                        }
                        else if (bits[i][k] == 0) {
                            bits[j][k] = 1;
                        }
                        else if (bits[j][k] == 0) {
                            bits[i][k] = 1;
                        }
                    }
                    else {
                        if (bits[i][k] == 1 || bits[j][k] == 1) {
                            cout << "NO" << endl;
                            return;
                        }
                        bits[i][k] = 0;
                        bits[j][k] = 0;
                    }
                }
            }
        }
    }

    // rep(i, 0, n) {
    //     per(k, 30, 0) {
    //         cout << bits[i][k];
    //     }
    //     cout << endl;
    // }

    cout << "YES" << endl;
    rep(i, 0, n) {
        int b = 0;
        rep(k, 0, 30) {
            b |= (bits[i][k]>0)*(1<<k);
        }
        cout << b << " ";
    }
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

