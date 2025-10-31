#include <bits/stdc++.h>
#include <algorithm>  
#include <climits>    
using namespace std;

string lcs(const string &a, const string &b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // tabla
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    string lcs_str;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs_str.push_back(a[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs_str.begin(), lcs_str.end());
    return lcs_str;
}


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
        vector<string> nums = split_ll(line, ' ');
        string a = nums[0];
        string b = nums[1];
        cout << lcs(a, b).size() << endl;




    }
    return 0;
}
