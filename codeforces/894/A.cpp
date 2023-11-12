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

    string S;
    cin >> S;
    int n = S.size();

    vi Q(n+1);
    Q[0] = 0;
    rep(i, 0, n) {
        if (S[i] == 'Q') Q[i+1] = Q[i] + 1;
        else Q[i+1] = Q[i];
    }


    ll ans = 0;
    ll tsum = Q[n];
    rep(i, 0, n) {
        if (S[i] == 'A') {
            ans += Q[i+1] * (tsum - Q[i+1]);
        }
    }

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
