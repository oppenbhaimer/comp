#include <bits/stdc++.h>
#include <ostream>
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

    deque<int> small, big;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'b') {
            if (!small.empty()) small.pop_back();
        }
        else if (s[i] == 'B') {
            if (!big.empty()) big.pop_back();
        }
        else if (s[i] >= 'a') {
            small.push_back(i);
        }
        else {
            big.push_back(i);
        }
    }

    vector<char> t;
    while (!small.empty() || !big.empty()) {
        if (small.empty()) {
            // push all from big 
            while (!big.empty()) {
                t.push_back(s[big.front()]);
                big.pop_front();
            }
            break;
        }
        if (big.empty()) {
            while (!small.empty()) {
                t.push_back(s[small.front()]);
                small.pop_front();
            }
            break;
        }
        if (small.front() < big.front()) {
            t.push_back(s[small.front()]);
            small.pop_front();
        }
        else {
            t.push_back(s[big.front()]);
            big.pop_front();
        }
    }

    for (char ch : t) cout << ch;
    cout << endl;
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

