#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char, int> residuoPorLetra = {
        {'T', 0}, {'R', 1}, {'W', 2}, {'A', 3}, {'G', 4}, {'M', 5},
        {'Y', 6}, {'F', 7}, {'P', 8}, {'D', 9}, {'X', 10}, {'B', 11},
        {'N', 12}, {'J', 13}, {'Z', 14}, {'S', 15}, {'Q', 16}, {'V', 17},
        {'H', 18}, {'L', 19}, {'C', 20}, {'K', 21}, {'E', 22}
    };

    int c;
    cin >> c;
    cin.ignore();

    for (int caso = 0; caso < c; caso++) {
        string linea;
        getline(cin, linea);
        int totales = 0;

        // encontrar las posiciones de los '?'
        vector<int> vacios;
        for (int i = 0; i < linea.size(); i++) {
            if (linea[i] == '?') {
                vacios.push_back(i);
            }
        }

        char letra = linea[8];
        int faltas = vacios.size();


        int valor = residuoPorLetra[letra];

        int combinaciones = 1;
        for (int i = 0; i < faltas; i++) {
            combinaciones *= 10;
        }

        for (int k = 0; k < combinaciones; k++) {
            string intento = linea;
            int temp = k;

            // remplazar los '?'
            for (int m = 0; m < faltas; m++) {
                int digito = temp % 10;
                temp /= 10;
                intento[vacios[m]] = '0' + digito;
            }

            // validacion
            string numeroStr = intento.substr(0, 8);
            long numero = stol(numeroStr);
            if (numero % 23 == valor) {
                totales++;
            }
        }

        cout << totales << "\n";
    }

    return 0;
}