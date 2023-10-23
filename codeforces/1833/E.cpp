
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

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

namespace ds {

// taken from cp-algorithms.com
class dsu {

    public:

    unordered_map<int,int> parent;
    unordered_map<int,int> size;

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

};

void solve() {
    int n;
    cin >> n;

    vector<int> C(n+1, 0);
    vector<bool> nocyc(n+1, false);
    ds::dsu D;
    rep(i, 1, n+1) D.make_set(i);

    rep(i, 1, n+1) {
        int t;
        cin >> t;
        C[t]++;
        C[i]++;

        D.union_sets(t, i);
    }

    vector<unordered_set<int>> groups(n+1, unordered_set<int>());
    rep(i, 1, n+1) {
        groups[D.find_set(i)].insert(i);
    }

    int n_cycles = 0;
    int n_chains = 0;
    // cout << "\n";
    for (auto G : groups) {
        if (G.size() == 0) continue;
        // for (int i : G) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        if (G.size() == 2) {
            n_chains++;
            continue;
        }
        bool chain = false;
        for (int i : G) {
            if (C[i] != 2) {
                chain = true;
                break;
            }
        }
        if (chain) n_chains++;
        else n_cycles++;
    }

    cout << n_cycles + (n_chains > 0 ? 1 : 0) << " " << n_cycles + n_chains << "\n";
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
