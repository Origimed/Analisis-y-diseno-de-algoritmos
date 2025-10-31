#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 999999937;
    const int MAXN = 500; // necesitamos hasta n = 499 (porque n = h - 1)

    // DP de Pascal: C[n][k] = nCk mod MOD
    static int C[MAXN][MAXN];
    C[0][0] = 1;
    for (int n = 1; n < MAXN; ++n) {
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            C[n][k] = C[n-1][k-1] + C[n-1][k];
            if (C[n][k] >= MOD) C[n][k] -= MOD;
        }
    }

    int c;
    cin >> c;
    while (c--) {
        int h;
        cin >> h;
        int n = h - 1;
        int k = n / 2;
        cout << C[n][k] << "\n";
    }

    return 0;
}
