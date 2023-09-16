#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

vector<bool> sieve(1e4+5, false);
vector<int> primes;

void solve() {

    int l, r;
    cin >> l >> r;

    if (r%2 == 0) {
        if (r == 2) cout << "-1\n";
        else cout << r-2 << " " << 2 << "\n";
    }
    else if (l%2 == 0) {
        if (l == 2) {
            if (r-l < 2) cout << "-1\n";
            else cout << l << " " << 2 << "\n";
        }
        else cout << l-2 << " " << 2 << "\n";
    }
    else if ((r-l) >= 1) {
        if (r-3 <= 0) cout << "-1\n";
        else cout << r-3 << " " << 2 << "\n";
    }
    else {
        // both odd, decompose l into a + b such that gcd(a, b) > 1 
        bool factored = false;
        for (int i=0; primes[i]*primes[i] <= l; i++) {
            if (l % primes[i] == 0) {
                cout << primes[i] << " " << (l / primes[i] - 1) * primes[i] << "\n";
                factored = true;
                break;
            }
        }

        if (!factored) cout << "-1\n";
    }
}

void create_sieve() {

    for (int i=2; i<sieve.size(); i++) {
        if (sieve[i]) continue;
        // cout << i << " Potentially prime" << "\n";
        for (int j=2*i; j<sieve.size(); j+=i) {
            sieve[j] = true;
        }
        primes.push_back(i);
    }

}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    create_sieve();
    while (t-- > 0) {
        solve();
    }
    return 0;
}

