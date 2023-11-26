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

    string s;
    cin >> s;

    int ans = 0;
    rep(i, 0, n) {
        int ctr = 0;
        while (i<n && s[i] == '.') {ctr++; i++; }
        if (ctr == 1) ans += 1;
        else if (ctr == 2) ans += 2;
        else if (ctr > 2) {
            ans = 2;
            break;
        }
    }

    cout << ans << endl;

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

