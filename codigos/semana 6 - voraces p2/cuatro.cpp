#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<pair<long long,long long>> vp;
        vp.reserve(N);
        for (int i = 0; i < N; ++i) {
            long long L, R;
            cin >> L >> R;
            vp.emplace_back(L, R);
        }

        // ordenar por extremo derecho (R)
        sort(vp.begin(), vp.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        long long disparos = 0;
        long long ultimo = LLONG_MIN; // ultima columna 

        for (const auto& [L, R] : vp) {

            if (ultimo < L || ultimo > R) {
                ++disparos;
                ultimo = R; // dispara en el extremo derecho cubre optimo
            }
        }

        cout << disparos << "\n";
    }

    return 0;
}
