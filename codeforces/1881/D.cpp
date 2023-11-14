#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

vector<int> primes;

void init() {

    vector<bool> sieve(2000, false);
    // sieve 
    rep(i, 2, 2000) {
        if (sieve[i]) continue;
        else {
            primes.push_back(i);
            for (int j=i; j<2000; j+=i) {
                sieve[j] = true;
            }
        }
    }
}
    
void solve() {

    int n;
    cin >> n;
    vi A(n);
    rep(i, 0, n) cin >> A[i];

    unordered_map<int,int> fac_count;

    for (int d : A) {
        for (int i : primes) {
            while (d > 0 && d%i == 0) {
                fac_count[i] += 1;
                d /= i;
            }
        }
        fac_count[d] += 1;
    }

    for (auto p : fac_count) {
        if (p.second % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();

    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

