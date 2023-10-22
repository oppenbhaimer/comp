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
    vi A(n);
    rep(i, 0, n) {
        cin >> A[i];
        A[i] %= k;
    }

    rep(i, 0, n) {
        if (A[i] == 0) {
            cout << "0\n";
            return;
        }
    }

    if (k == 2) {
        cout << "1\n";
        return;
    }
    else if (k == 3) {
        rep(i, 0, n) {
            if (A[i] == 2) {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
    }
    else if (k == 4) {
        bool encountered_2 = false;
        rep(i, 0, n) {
            if (A[i] == 2) {
                if (encountered_2) {
                    cout << "0\n"; return;
                }
                encountered_2 = true;
            }
        }
        if (encountered_2) {
            cout << "1\n"; return;
        }
        rep(i, 0, n) {
            if (A[i] == 3) {
                cout << "1\n"; return;
            }
        }
        cout << "2\n";
    }
    else {
        cout << 5-*max_element(A.begin(), A.end()) << "\n";
    }

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

