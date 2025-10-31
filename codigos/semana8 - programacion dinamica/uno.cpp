#include <bits/stdc++.h>
using namespace std;

vector<long long> split_ll(const string& s, char delim) {
    vector<long long> out;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        if (!t.empty()) out.push_back(stoll(t));
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore();

    while (c--) {
        int casillas;
        cin >> casillas;
        cin.ignore();

        vector<long long> casillas_vec;
        while (casillas--)
        {
            long long n;
            cin >> n;
            cin.ignore();
            casillas_vec.push_back(n);
        }
        // programacion dinamica MIS problem
        vector<long long> dp(casillas_vec.size(), 0);
        for (size_t i = 0; i < casillas_vec.size(); ++i)
        {
            long long include = casillas_vec[i];
            if (i > 1) include += dp[i - 2];
            long long exclude = (i > 0) ? dp[i - 1] : 0;
            dp[i] = max(include, exclude);
        }
        cout << dp.back() << "\n";

    }

    return 0;
}
