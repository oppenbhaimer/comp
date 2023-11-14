#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

pair<int,int> rot90(pair<int,int> p) {
    return {p.second, -p.first};
}

void solve() {

    int n;
    cin >> n;

    vector<string> M(n);
    rep(i, 0, n) {
        string s;
        cin >> s;
        M[i] = s;
    }

    ll n_ops = 0;
    rep(i, 0, n/2) {
        rep(j, 0, n/2) {
            vector<int> F(26, 0);

            F[M[i]    [j]     - 'a']++;
            F[M[j]    [n-1-i] - 'a']++;
            F[M[n-1-i][n-1-j] - 'a']++;
            F[M[n-1-j][i]     - 'a']++;

            int e_idx = -1;
            for (int i=25; i>=0; i--) {
                if (F[i] >= 1) {
                    if (e_idx != -1) {
                        n_ops += F[i]*(e_idx - i);
                    }
                    else {
                        e_idx = i;
                    }
                }
            }
        }
    }

    cout << n_ops << endl;
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

