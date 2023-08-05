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
    int n;
    cin >> n;
    vector<int> A(n+1, 0);
    rep(i, 0, n) {
        cin >> A[i+1];
    }

    int gm = A[0];
    rep(i, 1, n) {
        if (A[i] >= A[i-1] && A[i] > A[i+1] && A[i] > gm) gm = A[i];
    }

    cout << gm << endl;

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
