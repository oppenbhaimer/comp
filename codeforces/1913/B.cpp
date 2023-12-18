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

    string s;
    cin >> s;
    int n = s.size();

    vector<int> M(n, -1);

    int cost = 0;
    int i0 = 0, i1 = 0;
    rep(i, 0, n) {
        if (M[i] >= 0) {
            // for (int i : M) cout << i << " ";
            // cout << endl;
            continue;
        }
        if (s[i] == '1') {
            while (i0 < n && (s[i0] == '1' || (s[i0] == '0' && M[i0] != -1))) i0++;
            if (i0 >= n) continue;
            M[i0] = i;
            M[i] = i0;
        }
        else {
            while (i1 < n && (s[i1] == '0' || (s[i1] == '1' && M[i1] != -1))) i1++;
            if (i1 >= n) continue;
            M[i1] = i;
            M[i] = i1;
        }
        // for (int i : M) cout << i << " ";
        // cout << endl;
    }

    rep(i, 0, n) {
        if (M[i] == -1) {
            cout << (n-i) << endl;
            return;
        }
    }
    cout << 0 << endl;
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

