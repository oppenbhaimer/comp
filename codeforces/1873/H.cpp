#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, a, b) for (auto i = (a); i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

unordered_set<int> bridge_verts;

vector<unordered_set<int>> E;
vector<unordered_set<int>> E_bridge;

void IS_BRIDGE(int x, int y) {
    E_bridge[x].insert(y);
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void solve() {

    int a, b;
    cin >> n >> a >> b;
    adj = vector<vi>(n+1, vi());
    E = vector<unordered_set<int>>(n+1, unordered_set<int>());
    E_bridge = vector<unordered_set<int>>(n+1, unordered_set<int>());
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        E[x].insert(y);
        E[y].insert(x);
    }

    bridge_verts = unordered_set<int>();
    find_bridges();
    
    for (int i=1; i<=n; i++) {
        for (auto y : E_bridge[i]) {
            // cout << "(" << i << "," << y << ") ";
            E[i].erase(y);
            E[y].erase(i);
        }
    }
    // cout << "\n";

    unordered_set<int> bridge_verts;
    for (int i=1; i<=n; i++) {
        if (E[i].size() > 0) bridge_verts.insert(i);
    }

    // for (auto v : bridge_verts) cout << v << " "; cout << "\n";

    // now find distance to closest vertex not in bridge_verts via bfs 
    int d = 0;
    int cv = b;
    queue<int> S;
    vector<int> dist(n+1, 0);
    vector<bool> V(n+1, false);
    if (bridge_verts.find(b) == bridge_verts.end()) {
        S.push(b);
        V[b] = true;
        while (!S.empty()) {
            int t = S.front();
            S.pop();
            for (int u : adj[t]) {
                if (!V[u]) {
                    V[u] = true;
                    dist[u] = dist[t]+1;
                    if (bridge_verts.find(u) != bridge_verts.end()) {
                        d = dist[u];
                        cv = u;
                        break;
                    }
                    S.push(u);
                }
            }
        }
    }

    // found cv with dist d 
    // now dfs to cv from a 
    S = queue<int>();
    V.assign(n+1, false);
    dist.assign(n+1, 0);
    S.push(a);
    V[a] = true;
    int dp = 0;
    while (!S.empty()) {
        int t = S.front();
        S.pop();
        for (int u : adj[t]) {
            if (!V[u]) {
                V[u] = true;
                dist[u] = dist[t]+1;
                if (u == cv) {
                    dp = dist[u];
                    break;
                }
                S.push(u);
            }
        }
    }

    // cout << cv << " " << dp << " " << d << " ";
    if (dp <= d) cout << "NO\n";
    else cout << "YES\n";

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

