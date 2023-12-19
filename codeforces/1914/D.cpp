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

    vector<pair<int,int>> A(n), B(n), C(n);
    rep(i, 0, n) {int t; cin >> t; A[i] = {i, t};}
    rep(i, 0, n) {int t; cin >> t; B[i] = {i, t};}
    rep(i, 0, n) {int t; cin >> t; C[i] = {i, t};}

    std::sort(A.begin(), A.end(), [](auto &left, auto &right) {return left.second > right.second;});
    std::sort(B.begin(), B.end(), [](auto &left, auto &right) {return left.second > right.second;});
    std::sort(C.begin(), C.end(), [](auto &left, auto &right) {return left.second > right.second;});

    // three largest days 
    int msum = 0;
    int l = 3;
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            for (int k=0; k<l; k++) {
                auto [da,a] = A[i];
                auto [db,b] = B[j];
                auto [dc,c] = C[k];
                if (da == db || db == dc || dc == da) continue;
                msum = max(msum, a+b+c);
            }
        }
    }

    cout << msum << endl;
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

