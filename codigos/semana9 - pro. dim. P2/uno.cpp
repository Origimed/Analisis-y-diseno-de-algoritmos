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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore();

    while (c--) {
        string line;
        getline(cin, line);
        vector<long long> nums = split_ll(line, ' ');

        long long M = nums[0];
        vector<long long> piles(nums.begin() + 1, nums.end());

        vector<long long> denominaciones;

        for (long long pile : piles) {
            denominaciones.push_back(pile);
        }

        long long N = denominaciones.size();
        vector<vector<int>> A(N + 1, vector<int>(M + 1, INT_MAX));

        // casos base
        for (int i = 0; i <= N; i++) A[i][0] = 0;  // cantidad 0 = 0 monedas
        for (int j = 1; j <= M; j++) A[0][j] = INT_MAX;  // sin monedas no se puede

        // tabla
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (denominaciones[i - 1] <= j) {
                    int k = j - denominaciones[i - 1];
                    if (A[i][k] != INT_MAX)
                        A[i][j] = min(1 + A[i][k], A[i - 1][j]);
                    else
                        A[i][j] = A[i - 1][j];
                } else {
                    A[i][j] = A[i - 1][j];
                }
            }
        }


        cout << A[N][M] << endl;


    }
    return 0;
}
