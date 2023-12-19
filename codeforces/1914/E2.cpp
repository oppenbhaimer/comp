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
    vi A(n), B(n);

    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];

    vector<pair<int,int>> C(n);
    rep(i, 0, n) C[i] = {i, A[i] + B[i]};

    std::sort(C.begin(), C.end(), [](auto &left, auto &right) {return left.second > right.second;});

    ll a_sum = 0, b_sum = 0;
    rep(i, 0, n) {
        if (i%2 == 0) a_sum += A[C[i].first]-1;
        else b_sum += B[C[i].first]-1;
    }

    cout << a_sum - b_sum << endl;
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

