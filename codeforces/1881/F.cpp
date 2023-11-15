#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, k;
    cin >> n >> k;

    vector<bool> M(n+1, false);
    rep(i, 0, k) {
        int t; cin >> t; 
        M[t] = true;
    }

    vector<vi> G(n+1, vi());

    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // dfs from 1 to farthest vertex
    vi D(n+1, 0);
    vector<bool> visited(n+1, false);

    stack<int> S;
    S.push(1);
    visited[1] = true;
    while (!S.empty()) {
        int v = S.top();
        S.pop();
        for (int u : G[v]) {
            if (visited[u]) continue;
            S.push(u);
            visited[u] = true;
            D[u] = D[v] + 1;
        }
    }

    // farthest red vertex
    // atleast one red vertex exists 
    int fv = -1;
    int fv_dist = -1;
    rep(i, 1, n+1) {
        if (D[i] > fv_dist && M[i]) {
            fv_dist = D[i];
            fv = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    fill(D.begin(), D.end(), 0);
    
    S.push(fv);
    visited[fv] = true;
    while (!S.empty()) {
        int v = S.top();
        S.pop();
        for (int u : G[v]) {
            if (visited[u]) continue;
            S.push(u);
            visited[u] = true;
            D[u] = D[v] + 1;
        }
    }

    fv = -1;
    fv_dist = -1;
    rep(i, 1, n+1) {
        if (D[i] > fv_dist && M[i]) {
            fv_dist = D[i];
            fv = i;
        }
    }

    cout << (fv_dist+1) / 2 << endl;

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

