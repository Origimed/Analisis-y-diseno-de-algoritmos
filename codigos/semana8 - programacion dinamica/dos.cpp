#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int casos;           // esto es N en el enunciado
        cin >> casos;

        map<long long, long long> costo;
        long long max_necesario = 0;
        max_necesario = max(max_necesario, (long long)casos);
        for (int i = 1; i <= casos; ++i) {
            long long p;
            cin >> p;
            costo[i] = p;
        }

        // programacion dinamica cut wire problem (minimo y maximo)
        vector<long long> dpMax(max_necesario + 1, 0);
        const long long INF = (long long)4e18;
        vector<long long> dpMin(max_necesario + 1, INF);
        dpMin[0] = 0;
        dpMax[0] = 0;

        for (long long i = 1; i <= max_necesario; ++i) {
            long long bestMax = costo[i];
            long long bestMin = costo[i];
            for (long long j = 1; j <= i / 2; ++j) {
                long long cutMax = dpMax[j] + dpMax[i - j];
                long long cutMin = dpMin[j] + dpMin[i - j];
                if (cutMax > bestMax) bestMax = cutMax;
                if (cutMin < bestMin) bestMin = cutMin;
            }
            dpMax[i] = bestMax;
            dpMin[i] = bestMin;
        }

        cout << dpMin[max_necesario] << " " << dpMax[max_necesario] << "\n";
    }

    return 0;
}
