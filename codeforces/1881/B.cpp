#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];

    sort(A.begin(), A.end());

    int a = A[2];
    int b = A[1];
    int c = A[0];

    if ((a == c || a == 2*c || a == 3*c) && (b == 2*c || b == c)) {
        cout << "YES" << endl;
    }
    else if ((a == 4*c) && b == c) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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

