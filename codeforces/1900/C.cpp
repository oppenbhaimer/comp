#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, a, b) for (auto i = (a); i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int min_changes(vector<pair<int,int>>& T, int root, string& labels) {

    auto [l, r] = T[root];
    if (l == 0 && r == 0) return 0;

    if (labels[root] == 'U') {
        int m = INT_MAX;
        if (l != 0) m = min(m, min_changes(T, l, labels));
        if (r != 0) m = min(m, min_changes(T, r, labels));
        return 1 + m;
    }
    else if (labels[root] == 'R') {
        int m = INT_MAX;
        if (l != 0) m = min(m, 1+min_changes(T, l, labels));
        if (r != 0) m = min(m, min_changes(T, r, labels));
        return m;
    }
    else {
        int m = INT_MAX;
        if (l != 0) m = min(m, min_changes(T, l, labels));
        if (r != 0) m = min(m, 1+min_changes(T, r, labels));
        return m;
    }
}

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;
    s = "0" + s;

    vector<pair<int,int>> T(n+1);

    rep(i, 1, n+1) {
        auto& [l, r] = T[i];
        cin >> l >> r;
    }

    cout << min_changes(T, 1, s) << endl;

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

