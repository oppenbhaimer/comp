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

    int n, m;
    cin >> n >> m;
    vi A(m);
    vi C(n+1, 0);
    set<int> prev_win;
    rep(i, 0, m) {
        int v;
        cin >> v;
        C[v]++;
        if (prev_win.empty()) {
            prev_win.insert(v);
        }
        else if (C[*prev_win.begin()] < C[v]) {
            prev_win.clear();
            prev_win.insert(v); 
        }
        else if (C[*prev_win.begin()] == C[v]) {
            prev_win.insert(v);
        }

        cout << *prev_win.begin() << endl;
    }
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

