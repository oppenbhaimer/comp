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
    vi A(n+1), C(n+1);
    rep(i, 1, n+1) cin >> A[i];
    rep(i, 1, n+1) cin >> C[i];

    vector<unordered_set<int>> G(n+1, unordered_set<int>());
    rep(i, 1, n+1) {
        G[A[i]].insert(i);
    }

    // rep(i, 1, n+1) {
    //     cout << i << ": ";
    //     for (int j : G[i]) cout << j << " ";
    //     cout << "\n";
    // }


    vector<bool> sold(n+1, false);
    vector<bool> in_cycle(n+1, false);
    rep(i, 1, n+1) {
        if (sold[i]) continue;
        int t = i;
        while (G[t].size() == 0) {
            cout << t << " ";
            sold[t] = true;
            G[A[t]].erase(t);
            t = A[t];
        }
    }
    // cout << "\n";

    // only left with cycles now
    vector<vector<int>> cycles;
    rep(i, 1, n+1) {
        if (sold[i] || in_cycle[i]) continue;
        int t = i;
        cycles.push_back(vector<int>());
        while (!in_cycle[t]) {
            cycles[cycles.size()-1].push_back(t);
            in_cycle[t] = true;
            t = A[t];
        }
    }


    // cout << "Cycles: \n";
    // for (auto v : cycles) {
    //     for (int i : v) cout << i << " ";
    //     cout << "\n";
    // }

    for (auto v : cycles) {
        int mv_idx = 0;
        int mv_val = C[v[0]];
        rep(i, 1, v.size()) {
            if (C[v[i]] < mv_val) {
                mv_val = C[v[i]];
                mv_idx = i;
            }
        }
        // cout << "mi = " << mv_idx << "\n";
        rep(i, 1, v.size()+1) {
            cout << v[(mv_idx+i)%v.size()] << " ";
        }
    }

    cout << "\n";
    // cout << "\n";

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

