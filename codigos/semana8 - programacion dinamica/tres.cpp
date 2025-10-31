#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;
    vector<int> cost(P), weight(P);
    for (int i = 0; i < P; ++i) cin >> cost[i] >> weight[i];

    int J;
    cin >> J;
    vector<int> cap(J);
    int maxCap = 0;
    for (int i = 0; i < J; ++i) {
        cin >> cap[i];
        if (cap[i] > maxCap) maxCap = cap[i];
    }

    // dp[c] = máximo valor (miles de pesos) para capacidad c
    vector<long long> dp(maxCap + 1, 0);

    // 0/1 knapsack: para cada producto actualizar de atrás hacia adelante
    for (int i = 0; i < P; ++i) {
        int w = weight[i];
        int v = cost[i];
        for (int c = maxCap; c >= w; --c) {
            dp[c] = max(dp[c], dp[c - w] + v);
        }
    }

    long long answer = 0;
    for (int i = 0; i < J; ++i) answer += dp[cap[i]];

    cout << answer << "\n";
    return 0;
}
