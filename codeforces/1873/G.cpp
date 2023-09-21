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

    string s;
    cin >> s;
    int n = s.length();
    vector<int> C(1, 0);

    int j = 0;
    for (int i=0; i<n; ) {
        while (i < n && s[i] == 'A') { 
            C[C.size()-1]++; i++;
        }
        while (i < n && s[i] == 'B') { C.push_back(0); i++; }
    }

    int min = *min_element(C.begin(), C.end());
    ll sum = 0;
    for (auto i : C) sum += ((ll)i);
    sum -= min;
    cout << sum << "\n";

    // for (auto i : C) cout << i << " ";
    // cout << "\n";

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

