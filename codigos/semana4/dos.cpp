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
    if (!(cin >> c)) return 0;
    cin.ignore(); 

    while (c--) {
        string linea;
        getline(cin, linea);
        vector<long long> entrada = split_ll(linea, ' ');

        
        int tiempo = entrada[0];
        long best = tiempo;
        vector<long long> canciones(entrada.begin() + 1, entrada.end());

        auto nextCombination = [](vector<int>& c) -> bool {
            for (size_t i = 0; i < c.size(); ++i) {
                if (c[i] == 0) {
                    c[i] = 1;
                    for (size_t j = 0; j < i; ++j) c[j] = 0;
                    return true;
                }
            }
            return false; // no hay más
        };

        vector<int> csel(canciones.size(), 0);
        long long slns = 0; // cantidad de subconjuntos que suman exactamente M

        auto process = [&](const vector<int>& c) {
            long sum = 0;
            for (size_t i = 0; i < c.size(); ++i) {
                if (c[i]) sum += canciones[i];
            }
            if (sum == tiempo) ++slns;
            if (sum <= tiempo) best = min(best, tiempo - sum);
        };

        process(csel);
        while (best != 0 && nextCombination(csel)) {
            process(csel);
        }

        cout << best << "\n";

        
    }

    return 0;
}
