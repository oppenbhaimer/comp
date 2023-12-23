#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, a, b) for (auto i = (a); i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int upd_size(vector<vi>& G, vi& size, int v) {

    int vs = 1;
    for (int child : G[v]) {
        vs += upd_size(G, size, child);
    }

    size[v] = vs;
    return vs;
}

int get_size(vector<vi>& G, vi& size, int v, int k) {
    int tot=0, mc=-1;

    for (int child : G[v]) {
        tot += size[child];
        if (mc == -1 || size[child] > size[mc]) mc = child;
    }

    if (tot == 0) return 0;
    if (size[mc] - k <= tot - size[mc]) return (tot - k)/2;
    
    int a = tot - size[mc];
    return a + get_size(G, size, mc, max(0, k+a-1));
}

void solve() {

    int n;
    cin >> n;
    vector<vi> G(n+1, vi());
    vi size(n+1, 0);
    rep(i, 2, n+1) {
        int sup;
        cin >> sup;
        G[sup].push_back(i);
    }

    upd_size(G, size, 1);
    cout << get_size(G, size, 1, 0) << endl;
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

