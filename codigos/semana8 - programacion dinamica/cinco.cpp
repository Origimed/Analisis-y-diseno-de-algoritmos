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
    string line;
    getline(cin, line); 

    const int MAX_SUM = 50000; // 100  * 500
    while (c--) {
        getline(cin, line);
        vector<long long> coins_ll = split_ll(line, ' ');
        int total = 0;
        for (long long v : coins_ll) total += (int)v;

        bitset<MAX_SUM + 1> dp;
        dp.reset();
        dp[0] = 1;
        for (long long v : coins_ll) {
            int w = (int)v;
            dp |= (dp << w);
        }

        int half = total / 2;
        int best = 0;
        for (int s = half; s >= 0; --s) {
            if (dp[s]) { best = s; break; }
        }

        cout << (total - 2 * best) << "\n";
    }

    return 0;
}
