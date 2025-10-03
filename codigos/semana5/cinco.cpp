#include <bits/stdc++.h>
#include <map>

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

    while (true) {
        int c;
        if (!(cin >> c)) return 0;   // EOF
        cin.ignore();
        if (c == 0) break;

        multimap<long long, long long> mapa; // lo dejamos como en tu código
        mapa.clear();

        // guardamos también (phi, S, d) para poder ordenar con el criterio óptimo
        struct Item { long long phi, S, d; };
        vector<Item> v;
        v.reserve(c);

        for (int i = 0; i < c; i++) {
            string linea;
            getline(cin, linea);
            vector<long long> fortalezas = split_ll(linea, ' '); // S, K, B

            long long S = fortalezas[0];
            long long K = fortalezas[1];
            long long B = fortalezas[2];
            long long d = K + B;              // consumo neto tras ganar
            long long phi = S - d;            // clave de orden óptimo

            mapa.emplace(d, S);               // se conserva tal cual
            v.push_back({phi, S, d});
        }

        // Orden: S - (K+B) descendente; si empata, d ascendente (cualquier tie-break sirve)
        sort(v.begin(), v.end(), [](const Item& a, const Item& b){
            if (a.phi != b.phi) return a.phi > b.phi;
            return a.d < b.d;
        });

        long long total_soldados = 0;
        long long soldados_actuales = 0;

        for (const auto& f : v) {
            long long requerido = max(f.S, f.d);   // tener suficiente para ganar y para cubrir K+B
            if (soldados_actuales < requerido) {
                long long dif = requerido - soldados_actuales;
                total_soldados += dif;
                soldados_actuales += dif;
            }
            soldados_actuales -= f.d;              // después de la batalla
        }

        cout << total_soldados << '\n';
    }
    return 0;
}
