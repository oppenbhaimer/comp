#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> A(n);

    rep(i, 0, n) cin >> A[i];

    set<pair<ll,int>> S;
    ll ans = 0;
    ll sum = 0;
    rep(i, 0, n) {
        ll t = sum + A[i] - d*(i+1);
        ans = max(ans, t);
        if (A[i] > 0) {
            S.insert({A[i], i});
            sum += A[i];
            if (S.size() >= m) {
                sum -= S.begin()->first;
                S.erase(S.begin());
            }
        }
    }

    cout << ans << endl;
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

