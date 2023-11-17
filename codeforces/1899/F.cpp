#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, q;
    cin >> n >> q;

    rep(i, 0, n-1) {
        cout << i+1 << " " << i+2 << endl;
    }

    int p = n-1;
    rep(t, 0, q) {
        int d;
        cin >> d;

        if (p == d) cout << "-1 -1 -1" << endl;
        else cout << n << " " << p << " " << d << endl;
        p = d;
    }
    
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

