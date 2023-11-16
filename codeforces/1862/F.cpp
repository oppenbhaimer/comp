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

    int w, f;
    cin >> w >> f;
    int n;
    cin >> n;
    vector<int> A(n);
    int sum = 0;
    rep(i, 0, n) {
        cin >> A[i];
        sum += A[i];
    }

    int n_days = (sum + w + f - 1) / (w + f);

    vector<bool> DP(sum+1, false);
    DP[0] = true;
    rep(i, 0, n) {
        for (int w=sum; w-A[i] >= 0; w--) {
            DP[w] = DP[w] || DP[w-A[i]];
        }
    }

    int ans = MOD;
    for (int i=0; i<=sum; i++) {
        if (DP[i]) {
            ans = min(ans, max((i+w-1)/w, (sum-i+f-1)/f));
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

