#include <bits/stdc++.h>
#include <algorithm>  
#include <climits>    
using namespace std;

vector<string> split_ll(const string& s, char delim) {
    vector<string> out;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        if (!t.empty()) out.push_back(t);
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
        string line;
        getline(cin, line);
        vector<string> toks = split_ll(line, ' ');
        string s = toks[0];
        int n = (int)s.size();
        if (n <= 1) { 
            cout << 0 << "\n"; 
            continue; 
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // longitudes crecientes
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
                } else {
                    int rep = (i+1 <= j-1) ? dp[i+1][j-1] : 0; // reemplazo 
                    int delL = dp[i+1][j]; // borrar/insertar izquierdo
                    int delR = dp[i][j-1]; // borrar/insertar  derecho
                    dp[i][j] = min({rep, delL, delR}) + 1;
                }
            }
        }

        cout << dp[0][n-1] << "\n";
    }
    return 0;
}
