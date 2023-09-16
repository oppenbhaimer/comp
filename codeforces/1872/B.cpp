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

    vector<int> pos(n);
    vector<int> time(n);
    vector<int> fdist(n, 0);

    rep(i, 0, n) cin >> pos[i] >> time[i];

    rep(i, 0, n) {
        fdist[i] = pos[i] + (time[i]-1)/2;
    }

    cout << *min_element(fdist.begin(), fdist.end()) << "\n";
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

