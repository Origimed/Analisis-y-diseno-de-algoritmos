#include <bits/stdc++.h>
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

    const long INF = 1e9; // marca para "n.a"

    int c;
    cin >> c;
    cin.ignore();

    while (c--) {
        int destinos;
        cin >> destinos;
        cin.ignore();

        vector<vector<long>> g(destinos, vector<long>(destinos, INF));
        for (int i = 0; i < destinos; ++i) {
            string linea;
            getline(cin, linea);

            auto entrada = split_ll(linea, ' '); 

            for (int j = 0; j < destinos; ++j) {
                if (j >= entrada.size()) {
                    g[i][j] = INF; 
                } else if (entrada[j] == "n.a") {
                    g[i][j] = INF;
                } else {
                    try {
                        g[i][j] = stol(entrada[j]);
                    } catch (...) {
                        g[i][j] = INF; 
                    }
                }
            }
        }

        vector<int> p(destinos);
        iota(p.begin(), p.end(), 0);

        long best = LLONG_MAX;
        bool existe = false;

        do {
            long suma = 0; // suma en km
            bool ok = true;
            for (int i = 0; i < destinos - 1; ++i) {
                int u = p[i];
                int v = p[i + 1];
                if (g[u][v] >= INF) { ok = false; break; }
                suma += g[u][v];
            }
            if (ok) {
                existe = true;
                best = min(best, suma);
            }
        } while (next_permutation(p.begin(), p.end()));

        if (!existe) {
            cout << "imposible\n"; 
        } else {
            // redondear: precio = total_km / 10
            cout << lround((double)best / 10.0) << "\n";
        }
    }

    return 0;
}