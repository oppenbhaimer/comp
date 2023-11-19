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

    vi C(n);
    if (s[0] == 'B') C[0] = 1;
    rep(i, 1, n) {
        C[i] = C[i-1];
        if (s[i] == 'B') C[i]++;
    }

    if (C[n-1] == k) {
        cout << 0 << endl;
        return;
    }
    
    // rep(i, 0, n) cout << C[i] << " "; cout << endl;

    rep(i, 0, n) {
        if (C[n-1] - C[i] == k) {
            cout << "1\n" << i+1 << " A" << endl;
            return;
        }
        else if ((i+1) + (C[n-1] - C[i]) == k) {
            cout << "1\n" << i+1 << " B" << endl;
            return;
        }
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

