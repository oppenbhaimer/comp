#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    int t = 0;
    while (x.size() < m) {
        x = x + x;
        t += 1;
    }
    for (int i=0; i+m-1<x.size(); i++) {
        if (x.substr(i, m) == s) {
            cout << t << endl;
            return;
        }
    }
    x = x + x;
    t += 1;
    for (int i=0; i+m-1<x.size(); i++) {
        if (x.substr(i, m) == s) {
            cout << t << endl;
            return;
        }
    }
    cout << -1 << endl;
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

