#include <bits/stdc++.h>
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
    multimap<double, double> mapa; 

    while (c--) {
        int k;
        cin >> k;
        cin.ignore();

        mapa.clear();

        while (k--) {
            string linea;
            getline(cin, linea);
            vector<long long> multas = split_ll(linea, ' ');
            // multas[0] = t, multas[1] = c
            mapa.emplace((double)multas[0], (double)multas[1]);
        }

        map<long, double> coeficientes;

        long valor = 0;
        for (auto &par : mapa) {
            double t = par.first;
            double ci = par.second;
            double coeficiente = t / ci; // coeficiente t/c
            coeficientes[valor] = coeficiente;
            valor++;
        }

        // ordenar coeficientes de menor a mayor (menor t/c primero)
        vector<pair<double,double>> ordenado(coeficientes.begin(), coeficientes.end());
        sort(ordenado.begin(), ordenado.end(),
             [](const pair<double,double> &a, const pair<double,double> &b) {
                 return a.second < b.second;
             });

        // reconstruir items (t, c) en el mismo orden de enumeración usado arriba
        vector<pair<long long,long long>> items;
        items.reserve(mapa.size());
        for (auto &par : mapa) {
            long long t = (long long) llround(par.first);
            long long ci = (long long) llround(par.second);
            items.emplace_back(t, ci);
        }

        // calcular la multa total mínima siguiendo el orden "ordenado"
        long long sum_t = 0;
        long long ans = 0;
        for (auto &par : ordenado) {
            long idx = (long) par.first; // índice asignado en coeficientes
            long long t = items[idx].first;
            long long ci = items[idx].second;
            ans += ci * sum_t; // multa por esperar antes de empezar este trabajo
            sum_t += t;
        }

        cout << ans << "\n";
    }
    return 0;
}
