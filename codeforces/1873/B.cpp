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
    vector<ll> A(n);
    ll min = LONG_MAX;
    ll prod = 0;
    ll t;
    rep(i, 0, n) {
        cin >> A[i];
        if (A[i] < min) min = A[i];
    }

    prod = 1;
    bool added = false;
    rep(i, 0, n) {
        if (A[i] == min && !added) {
            prod *= (A[i] + 1);
            added = true;
        }
        else prod *= A[i];
    }

    cout << prod << "\n";

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

