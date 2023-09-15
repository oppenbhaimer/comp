#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353
#define rep(i, a, b) for (auto i = (a); i < (b); i++)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

struct var {

    string s;
    ll n;

    var(): s{""}, n{0} {}

    var(string str) {

        s = str;

        n = 0;
        if (s.size() == 4 && s == "haha") {
            n = 1;
        }
        else if (s.size() == 5) {
            if (s.substr(0,4) == "haha") n += 1;
            if (s.substr(1,4) == "haha") n += 1;
        }
    }

    void concat(const var& s1, const var& s2) {

        // immutability!

        n = s1.n + s2.n;
        
        ll n0 = n;

        string temp = "";
        if (s1.s.size() < 3) temp += s1.s; 
        else temp += s1.s.substr(s1.s.size() - 3, 3);

        if (s2.s.size() < 3) temp += s2.s; 
        else temp += s2.s.substr(0, 3);

        if (temp.size() == 4 && temp == "haha") n += 1;
        else if (temp.size() == 5) {
            if (temp.substr(0,4) == "haha") n += 1;
            if (temp.substr(1,4)   == "haha") n += 1;
        }
        else if (temp.size() == 6) {
            if (temp.substr(0,4) == "haha") n += 1;
            if (temp.substr(1,4) == "haha") n += 1;
            if (temp.substr(2,4) == "haha") n += 1;
        }

        s = s1.s + s2.s;
        if (s.size() >= 7) s = s.substr(0,3) + "@" + s.substr(s.length() - 3, 3);

        // std::cout << temp << " " << n - n0 << "\n";

    }

};

void solve(int t) {

    int n;
    cin >> n;
    cin.ignore();

    unordered_map<string, var> vars;
    string last_modified_var;
    rep(i, 0, n) {

        string stmt;
        getline(cin, stmt);
        // if (t == 1000 - 20) 
            // cout << stmt << "\n";
        if (stmt.find(':') != string::npos) {
            // assignment
            string name = stmt.substr(0, stmt.find(" := "));
            stmt.erase(0, stmt.find(" := ") + 4);
            string value = stmt;

            var v(value);
            vars[name] = v;
            last_modified_var = name;
        }
        else {
            // summation
            string v = stmt.substr(0, stmt.find(" = "));
            stmt.erase(0, stmt.find(" = ") + 3);
            string v1 = stmt.substr(0, stmt.find(" + "));
            stmt.erase(0, stmt.find(" + ") + 3);
            string v2 = stmt;

            vars[v].concat(vars[v1], vars[v2]);
            last_modified_var = v;
        }
        string v = last_modified_var;
        // if (t == 1000 - 20) 
            // cout << v << " (" << vars[v].s << ", " << vars[v].n << ")" << "\n";
    }

    // for (auto [k, v] : vars) {

    //     cout << k << " (" << v.prefix << ", " << v.n << ", " << v.suffix << ")" << "\n";
    // }

    cout << vars[last_modified_var].n << "\n";

}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t-- > 0) {
        solve(t);
    }
    return 0;
}

