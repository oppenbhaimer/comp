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
    string s;
    cin >> s;

    int n_ops = 0;
    rep(i, 0, n) {
        if (s[i] == 'B') {
            n_ops += 1;
            for (int j=0; j<k && i+j<n; j++) s[i+j] = 'W';
            i += (k-1);
        }
    }

    cout << n_ops << "\n";
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

