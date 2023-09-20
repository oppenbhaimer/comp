#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, a, b) for (auto i = (a); i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;

void solve() {

    string s, t;
    cin >> s >> t;
    s = "0" + s;
    t = "0" + t;
    vector<vi> DP(s.length(), vi(t.length()));
    rep(i, 0, t.length()) DP[0][i] = 0;
    rep(i, 0, s.length()) DP[i][0] = 0;

    rep(i, 1, s.length()) {
        rep(j, 1, t.length()) {
            if (s[i] == t[j]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }

    // rep(i, 0, s.length()) {
    //     rep (j, 0, t.length()) {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    string lcs = "";
    int y = s.length()-1;
    int x = t.length()-1;
    while (y > 0 && x > 0) {
        if (DP[y][x] == DP[y-1][x]) y--;
        else if (DP[y][x] == DP[y][x-1]) x--;
        else if (DP[y][x] != DP[y-1][x-1]) {
            lcs = s[y] + lcs;
            y--;
            x--;
        }
    }


    cout << lcs << "\n";

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

