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

    string pos;
    cin >> pos;
    int row = pos[0] - 'a';
    int col = pos[1] - '1';

    vector<string> moves;
    rep(i, 0, 8) {
        if (i != row) {
            string s = "";
            s += (i+'a');
            s += pos[1];
            moves.push_back(s);
        }
    }
    rep(j, 0, 8) {
        if (j != col) {
            string s = "";
            s += pos[0];
            s += (j+'1');
            moves.push_back(s);
        }
    }

    for (auto s : moves) cout << s << endl;

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

