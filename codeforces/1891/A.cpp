
#include <bits/stdc++.h>
#include <iostream>
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
    // code here

    int n;
    cin >> n;
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    if (n <= 2) {
        cout << "YES\n";
        return;
    }

    rep(i, 2, 11) {
        bool decr = true;
        for (int j = (1<<(i-1)); j < n-1 && j < (1<<i) - 1; j++) {

            if (A[j+1] < A[j]) {
                // cout << j << " bad\n";
                decr = false;
            }
        }
        if (!decr) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
