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

    ll ans=0;
    int i=0;
    while (i < n && s[i] == 'B') i++;
    int ictr = 0;
    while(i < n) {
        int ac = 0;
        int bc = 0;
        while (i < n && s[i] == 'A') { ac++; i++; }
        while (i < n && s[i] == 'B') { bc++; i++; }
        if (bc == 0) break;
        ans += (ac + bc + ictr - 1);
        ictr = 1;
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

