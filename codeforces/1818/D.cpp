#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

int n, m;
vector<vi> adj;
vector<unordered_set<int>> adj_nobridge;
vector<bool> visited;
vector<int> tin, low;
int timer;

vector<pair<int,int>> bridges;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    adj = vector<vi>();
    adj_nobridge = vector<unordered_set<int>>();
    visited = vector<bool>();
    tin = vector<int>();
    low = vector<int>();

    bridges = vector<pair<int,int>>();
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
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }
        }
    }
}

void solve() {

    // cout << "Taking input" << endl;

    cin >> n >> m;

    adj.clear();
    adj_nobridge.clear();
    bridges.clear();
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    timer = 0;

    // cout << "Reset" << endl;

    rep(i, 0, n+1) {
        adj.push_back(vi());
        adj_nobridge.push_back(std::unordered_set<int>());
    }

    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adj_nobridge[u].insert(v);
        adj_nobridge[v].insert(u);
    }

    // cout << "Took input" << endl;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    for (auto p : bridges) {
        adj_nobridge[p.first].erase(p.second);
        adj_nobridge[p.second].erase(p.first);
    }

    // cout << "Got nobridge edges out" << endl;

    bool has_fish = false;
    vector<pair<int,int>> fish_edges;
    for (int i=1; i<=n; i++) {
        if (adj_nobridge[i].size() >= 2 && adj[i].size() >= 4) {
            has_fish = true;
            // bridge edge candidate
            // find smallest cycle w dfs(will contain only non-bridge edges)
            // pick any vertex in nobridge and bfs the path to it
            //
            // cout << "Candidate fish vertex " << i << endl;
            
            int v = *adj_nobridge[i].begin();
            adj_nobridge[i].erase(v);
            adj_nobridge[v].erase(i);
            fish_edges.push_back({i, v});

            queue<int> Q;
            vector<bool> visited(n+1, false);
            vector<int> parent(n+1, -1);
            Q.push(i);
            visited[i] = true;
            bool found = false;
            while (!Q.empty() && !found) {
                int t = Q.front();
                Q.pop();
                visited[t] = true;
                for (int u : adj_nobridge[t]) {
                    if (u == v) {
                        // found the cycle!
                        found = true;
                        visited[u] = true;
                        parent[u] = t;
                    }
                    if (!visited[u]) {
                        Q.push(u);
                        visited[u] = true;
                        parent[u] = t;
                    }
                }
            }

            int t;
            for (t=v; parent[t]!=i; t=parent[t]) {
                fish_edges.push_back({t,parent[t]});
            }
            fish_edges.push_back({t,i});

            int ctr = 0;
            for (int k : adj[i]) {
                if (k == t || k == v) continue;
                fish_edges.push_back({i, k});
                ctr++;
                if (ctr == 2) break;
            }
            // adj_nobridge[i].erase(t);
            // fish_edges.push_back({*adj_nobridge[i].begin(), i});
            // adj_nobridge[i].erase(adj_nobridge[i].begin());
            // fish_edges.push_back({*adj_nobridge[i].begin(), i});
            break;
        }
    }

    // cout << "Checked for fish" << endl;

    if (has_fish) {
        cout << "YES\n";
        cout << fish_edges.size() << endl;
        for (auto p : fish_edges) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
