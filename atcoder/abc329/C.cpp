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

    vi consec(26, 0);

    int sum = 0;
    int ctr = 1;
    rep(i, 1, n) {
        if (s[i] != s[i-1]) {
            consec[s[i-1]-'a'] = max(consec[s[i-1]-'a'], ctr);
            ctr = 1;
        }
        else ctr++;
    }

    consec[s[n-1]-'a'] = max(consec[s[n-1]-'a'], ctr);

    // rep(i, 0, 26) cout << consec[i] << " "; cout << endl;
    rep(i, 0, 26) {
        sum += consec[i];
    }

    cout << sum << endl;

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

