#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore(); 

    for(int caso = 0; caso < c; caso++) {
        string linea;
        getline(cin, linea);
        long long numero = stoll(linea);
        vector<int> digitos;
        for(int i = 0; i < linea.size(); i++) {
            digitos.push_back(linea[i] - '0');
        }

        if (digitos.size() < 2 || digitos.size()%2 != 0) {
            cout << "No\n";
            continue;
        }
        long mitad = digitos.size() / 2;

        sort(digitos.begin(), digitos.end());

        bool encontrado = false;
        do {
            vector<long long> primera(mitad);
            vector<long long> segunda(mitad);
            for(int i = 0; i < mitad; i++) {
                primera[i] = digitos[i];
                segunda[i] = digitos[i + mitad];
            }

            // convertir los numeros de primera y segunda a enteros
            long long num1 = 0;
            long long num2 = 0;
            for(int i = 0; i < mitad; i++) {
                num1 = num1 * 10 + primera[i];
                num2 = num2 * 10 + segunda[i];
            }
            long long total = num1 * num2;
            if (total == numero) {
                encontrado = true;
                break;
            }
            
        } while (next_permutation(digitos.begin(), digitos.end()));

        if (encontrado) {
            cout << "Heredero\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
