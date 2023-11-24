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
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    int m = *min_element(A.begin(), A.end());
    int M = *max_element(A.begin(), A.end());

    vector<int> ops;
    while (m != M) {
        if (M%2 == 0 && m%2 == 1) {
            ops.push_back(1);
            M = (M+1)/2;
            m = (m+1)/2;
        }
        else {
            ops.push_back(0);
            M /= 2;
            m /= 2;
        }
    }

    cout << ops.size() << endl;
    if (ops.size() <= n && ops.size() > 0) {
        for (int i : ops) cout << i << " ";
        cout << endl;
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

