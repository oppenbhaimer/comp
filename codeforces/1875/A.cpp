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

    int a, b, n;
    cin >> a >> b >> n;
    ll sum = b;
    bool gt_a = false;
    rep(i, 0, n) {
        int t;
        cin >> t;
        if (t > a-1) sum += (a-1);
        else sum += t;
    }
    cout << sum << endl;
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

