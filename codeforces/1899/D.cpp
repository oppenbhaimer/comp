#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n;
    cin >> n;
    map<int,int> freq;
    rep(i, 0, n) {
        int p;
        cin >> p;
        freq[p]++;
    }

    ll f1 = (ll)freq[1], f2 = (ll)freq[2];
    ll sum = f1 * f2;

    for (auto p : freq) {
        ll f = (ll)p.second;
        sum += (f*(f-1))/2;
    }

    cout << sum << endl;

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