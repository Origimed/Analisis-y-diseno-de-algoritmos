#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore(); // limpia el buffer de entrada

    for (int i = 0; i < c; i++) {
        string entrada;
        getline(cin, entrada);
        if (entrada.empty()) { --i; continue; } // por si hay líneas vacías

        long long n = stoll(entrada);

        // n < 1e6 -> n^2 < 1e12 (cabe en 64 bits)
        long long cuadrado = n * n;

        // dígitos de n
        int d = (int)to_string(n).size();

        // 10^d
        long long modn = 1;
        for (int k = 0; k < d; ++k) modn *= 10;

        // separar izquierda y derecha con d dígitos en la derecha
        long long der_num = cuadrado % modn;
        long long izq_num = cuadrado / modn;

        // comprobar Kaprekar (derecha no nula)
        if (der_num != 0 && izq_num + der_num == n) {
            cout << "KAP\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
