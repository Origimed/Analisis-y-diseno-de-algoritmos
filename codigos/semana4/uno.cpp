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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia línea

    while (c--) {
        string linea;
        getline(cin, linea);
        auto entrada = split_ll(linea, ' ');
        if (entrada.empty()) { cout << 0 << "\n"; continue; }

        long long k = entrada[0];
        vector<long long> numeros(entrada.begin() + 1, entrada.end());

        sort(numeros.begin(), numeros.end());
        long long conteo = 0;
        do {
            long long lado01 = numeros[0] + numeros[3] + numeros[4] + numeros[1];
            if (lado01 != k) continue; // poda
            long long lado12 = numeros[1] + numeros[5] + numeros[6] + numeros[2];
            if (lado12 != k) continue;
            long long lado20 = numeros[2] + numeros[7] + numeros[8] + numeros[0];
            if (lado20 != k) continue;
            ++conteo;
        } while (next_permutation(numeros.begin(), numeros.end()));

        cout << conteo << "\n";
    }
    return 0;
}
