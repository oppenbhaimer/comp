#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    int min_x = 100;
    rep(t, 0, q) {

        int x;
        cin >> x;

        if (min_x != 100 && min_x <= x) continue;

        rep(i, 0, n) {
            if (__builtin_ctz(A[i]) >= x) {
                A[i] |= (1<<(x-1));
            }
        }
        
        if (x < min_x) min_x = x;
    }

    rep(i, 0, n) cout << A[i] << " ";
    cout << "\n";

}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
