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

    int n, q;
    cin >> n >> q;
    vector<unordered_map<int,int>> M(n+1, unordered_map<int,int>());
    rep(i, 1, n+1) {
        int t;
        cin >> t;
        M[i][t]++;
    }
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        // TC: O(min(m,n))
        if (M[a].size() > M[b].size()) {
            swap(M[a], M[b]);
        }
        for (auto p : M[a]) {
            M[b][p.first] += p.second;
        }
        M[a].clear();
        cout << M[b].size() << endl;
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

