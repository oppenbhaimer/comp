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


    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int freqmap[26];
    for (int i=0; i<26; i++) freqmap[i] = 0;

    for (char c : s) {
        freqmap[c-'a'] += 1;
    }

    int n_odd = 0;
    int n_even = 0;
    for (int i : freqmap) {
        if (i == 0) continue;
        if (i%2 == 0) n_even++;
        else n_odd++;
    }

    if (n_odd-1 > k) {
        cout << "NO\n"; return;
    }

    // cout << n_odd << " " << n_even << " YES\n"; 
    cout << "YES\n"; 

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

