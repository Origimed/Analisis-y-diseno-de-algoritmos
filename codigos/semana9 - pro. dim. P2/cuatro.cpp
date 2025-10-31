#include <bits/stdc++.h>
#include <algorithm>  
#include <climits>    
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

// LCS 
vector<long long> lcs_vec(const vector<long long> &a, const vector<long long> &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<long long> res;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            res.push_back(a[i-1]);
            --i; --j;
        } else if (dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore();

    for (int caso = 0; caso < c; ++caso) {
        int k;
        cin >> k;
        cin.ignore();

        vector<long long> valores;

        string lineFinal;
        getline(cin, lineFinal); 
        vector<long long> numsFinal = split_ll(lineFinal, ' ');
        for (int i = 0; i < k; i++) {
            string line;
            getline(cin, line);
            vector<long long> nums = split_ll(line, ' ');

            vector<long long> ans = lcs_vec(numsFinal, nums);
            double final = numsFinal.empty() ? 0.0 : (100.0 * static_cast<double>(ans.size()) / static_cast<double>(numsFinal.size()));
            long long pct = llround(final);
            valores.push_back(pct);
        }

        cout << "caso "<< caso + 1 << ":" << endl;
        for (long long val : valores) {
            cout << " " << val << endl;
        }
        cout << endl;
        


    }
    return 0;
}
