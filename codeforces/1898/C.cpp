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

    int n, m, k;
    cin >> n >> m >> k;

    if (k < (m+n-2)) { cout << "NO" << endl;  return; }

    int s = k - (m+n-2);

    if (s%2 == 0) {
        cout << "YES" << endl;
        // n rows, m columns
        rep(j, 0, n) {
            rep(i, 0, m-1) {
                if (j == 0 || j == n-1) {
                    if (i%2 == 0) cout << "R ";
                    else cout << "B ";
                }
                else cout << "R ";
            }
            cout << endl;
        }
        rep(i, 0, n-1) {
            rep(j, 0, m) {
                if (j == m-1) {
                    if (m%2 == 1) {
                        // rbrb -> r
                        if (i%2 == 1) cout << "B ";
                        else cout << "R ";
                    }
                    else {
                        // rbr
                        if (i%2 == 1) cout << "R ";
                        else cout << "B ";
                    }
                }
                else cout << "B ";
            }
            cout << endl;
        }
    }
    else cout << "NO" << endl;

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

