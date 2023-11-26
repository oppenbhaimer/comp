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

    int a, b, c;
    cin >> a >> b >> c;

    bool ap, bp, cp;
    ap = bp = cp = false;
    if (a%2 == b%2 && b%2 == c%2) cout << "1 1 1\n";
    else if (a%2 == b%2) cout << "0 0 1\n";
    else if (b%2 == c%2) cout << "1 0 0\n";
    else if (c%2 == a%2) cout << "0 1 0\n";

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

