#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void solve() {

    int n, k, x;
    cin >> n >> k >> x;

    int sum = 0;
    int m = min(x,min(k,n));
    if (m == n && n != k) cout << "-1\n";
    else if (m == x && x < k-1) cout << "-1\n";
    else if (x == k) cout << m*(m-1)/2 + (n-m)*(k-1) << "\n";
    else cout << m*(m-1)/2 + (n-m)*x << "\n";

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

