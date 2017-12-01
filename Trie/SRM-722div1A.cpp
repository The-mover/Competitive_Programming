#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

using ll = long long;

class TCPhoneHome {
    public:

    struct node {
        bool endpoint;
        node* next[11 + 1];
        node() {
            endpoint = false;
            for(int i = 0; i < 11; i++) {
                next[i] = NULL;
            }
        }
    } * root;

    void _insert(string str, int len) {
        node* curr = root;
        for(int i = 0; i < len; i++) {
            int id = str[i] - '0';
            if(curr->next[id] == NULL)
                curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->endpoint = true;
    }

    void del(node* cur) {
        for (int i = 0; i < 11; i++)
            if (cur->next[i])
                del(cur->next[i]);

        delete (cur);
    }

    ll dfs(node* cur, int digits ) {
        ll ret = 0;
        if( cur->endpoint ) {
            ret = 1ll;
            for( int i=0; i <digits; i++ ) {
                ret *= 10;
            }
            return ret;
        }
        for(int i=0; i<11; i++) {
            if( cur->next[i] ) {
                ret += dfs( cur->next[i], digits - 1 );
            }
        }
        return ret;
    }

    long long validNumbers(int digits, vector<string> specialPrefixes) {

        ll ans = 1;
        for(int i=0; i<digits; i++) {
            ans *= 10;
        }

        root = new node();
        for(int i=0; i<specialPrefixes.size(); i++) {
            string s = specialPrefixes[i];
            int len = s.size();
            _insert(s, len);
        }
        ans -= dfs( root, digits );
        del(root);
        return ans;
    }
};

// CUT begin
ifstream data("TCPhoneHome.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int digits, vector<string> specialPrefixes, long long __expected) {
    time_t startClock = clock();
    TCPhoneHome *instance = new TCPhoneHome();
    long long __result = instance->validNumbers(digits, specialPrefixes);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int digits;
        from_stream(digits);
        vector<string> specialPrefixes;
        from_stream(specialPrefixes);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, specialPrefixes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1512122963;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TCPhoneHome (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
