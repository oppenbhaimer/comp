#include <algorithm>
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

    int q;
    cin >> q;

    multiset<int> L, R;

    while (q-- > 0) {

        char c;
        int l, r;
        cin >> c >> l >> r;

        if (c == '+') {
            L.insert(l);
            R.insert(r);
        }
        else {
            L.erase(L.lower_bound(l));
            R.erase(R.lower_bound(r));
        }

        if (L.empty() || R.empty()) cout << "NO\n";
        else if (*L.rbegin() > *R.begin()) cout << "YES\n";
        else cout << "NO\n";
    }

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

